#include "system.hpp"

#include <iostream>
#include <opencv/cv.hpp>

void VideoInputSystem::treatEvent() {
    cv::VideoCapture video(0);
    cv::Mat frame, hsv, mask;

    float oldBary = 0.f;
    while(mIsRunning) {
        video >> frame;
        cv::imshow("Camera", frame);
        cv::waitKey(10);

        cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
        cv::inRange(hsv, cv::Scalar(0, 0, 128), cv::Scalar(30, 192, 255), mask);
        cv::imshow("treated image", mask);

        float bary(0.f);
        int counter(0);
        for(auto y = 0; y < mask.size().height; ++y)
            for(auto x = 0; x < mask.size().width; ++x)
                if(mask.ptr()[y * mask.size().width + x] == 0) {
                    ++counter;
                    bary += x;
                }

        if(counter != 0)
            bary /= counter;

        float speed = bary - oldBary;
        oldBary = bary;

        if(fabs(speed) > 5)
            mDisplacement = -speed / 2.;

        else
            mDisplacement = 0.f;

        std::cout << speed << std::endl;
    }
}

VideoInputSystem::VideoInputSystem() : mThread(&VideoInputSystem::treatEvent, this) {
    cv::namedWindow("Camera");
    cv::namedWindow("treated image");
}

VideoInputSystem::~VideoInputSystem() {
    mIsRunning = false;
    mThread.join();
}

void VideoInputSystem::run() {
    static auto clock = sf::Clock();

    for(auto i = 0u; i < World::world.numberEntities; ++i) {
        if(World::world.used[i] &&
           World::world.hasComponents[i][INPUT]) {
            auto &input = World::world.inputs[i];

            input.displacement = mDisplacement;
            input.toShot = false;

            if(clock.getElapsedTime().asMilliseconds() > 2000) {
                input.toShot = true;
                clock.restart();
            }
        }
    }
}

void KeyboardInputSystem::run() {
    static auto clock = sf::Clock();
    for(auto i = 0u; i < World::world.numberEntities; ++i) {
        if(World::world.used[i] &&
           World::world.hasComponents[i][INPUT]) {
            auto &input = World::world.inputs[i];
            input.displacement = 0.f;
            input.toShot = false;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                input.displacement -= 3.f;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                input.displacement += 3.f;

            if(clock.getElapsedTime().asMilliseconds() > 2000) {
                input.toShot = true;
                clock.restart();
            }
        }
    }
}

void ApplyInputSystem::run() {
    for(auto i = 0u; i < World::world.numberEntities; ++i) {
        if(World::world.used[i] &&
           World::world.hasComponents[i][INPUT]) {
            if(World::world.hasComponents[i][VELOCITY])
                World::world.velocities[i].x = World::world.inputs[i].displacement;

            if(World::world.hasComponents[i][AABB])
                if(World::world.inputs[i].toShot)
                    createMissile(World::world.aabbs[i].x + World::world.aabbs[i].w / 2.f,
                                  World::world.aabbs[i].y, true);
        }
    }
}
