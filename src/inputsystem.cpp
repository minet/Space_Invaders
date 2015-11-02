#include "system.hpp"

#include <iostream>

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
