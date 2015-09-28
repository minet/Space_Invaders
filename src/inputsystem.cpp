#include "system.hpp"

void KeyboardInputSystem::run() {    
    for(auto i = 0u; i < World::world.numberEntities; ++i) {
        if(World::world.used[i] &&
           World::world.hasComponents[i][INPUT]) {
            auto &input = World::world.inputs[i];
            input.displacement = 0.f;
            input.toShot = false;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                input.displacement -= 1.f;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                input.displacement += 1.f;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                input.toShot = true;
        }
    }
}

void ApplyInputSystem::run() {
    for(auto i = 0u; i < World::world.numberEntities; ++i) {
        if(World::world.used[i] &&
           World::world.hasComponents[i][INPUT]) {
            if(World::world.hasComponents[i][VELOCITY])
                World::world.velocities[i].x = World::world.inputs[i].displacement;

            if(World::world.hasComponents[i][POSITION])
                if(World::world.inputs[i].toShot)
                    createMissile(World::world.positions[i], true);
        }
    }
}
