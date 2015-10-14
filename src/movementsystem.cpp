#include "system.hpp"


void MovementSystem::run() {
    for(auto i(0u); i < World::world.numberEntities; ++i) {
        if(World::world.used[i] &&
           World::world.hasComponents[i][VELOCITY] &&
           World::world.hasComponents[i][AABB]) {
            World::world.aabbs[i].x += World::world.velocities[i].x;
            World::world.aabbs[i].y += World::world.velocities[i].y;
        }
    }
}
