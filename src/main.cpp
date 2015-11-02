#include "game.hpp"
#include <opencv/cv.hpp>

using namespace cv;

sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);
/*
int main() {
    srand(time(NULL));

    Game game(window);

    game.create();

    static sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);

    while(window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        timeSinceLastUpdate += clock.restart();

        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            game.run();
        }
    }

    return 0;
}
*/

int main() {
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
            return -1;

    Mat edges;
    namedWindow("edges",1);

    for(;;) {
        Mat frame;
        cap >> frame; // get a new frame from camera
        imshow("edges", frame);
        if(waitKey(30) >= 0) break;
    }

    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
