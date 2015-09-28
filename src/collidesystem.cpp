#include "system.hpp"

void CollideSystem::run() {

    for(auto i = 0u; i < World::world.numberEntities; ++i) {

        if (World::world.used[i] &&
            World::world.hasComponents[i][AABB] &&
            World::world.hasComponents[i][POSITION]) {

            if (World::world.hasComponents[i][INPUT] &&
                World::world.aabbs[i].x < 0) {

               World::world.aabbs[i].x = 0;
               World::world.positions[i].x = 0;

            }

            if (World::world.hasComponents[i][INPUT] &&
                World::world.aabbs[i].x > window.getSize().x - World::world.aabbs[i].w) {

               World::world.aabbs[i].x = window.getSize().x - World::world.aabbs[i].w;
               World::world.positions[i].x = window.getSize().x - World::world.aabbs[i].w;

            }

            if (World::world.hasComponents[i][IA] &&
                World::world.aabbs[i].x < 0) {

               World::world.aabbs[i].x = 0;
               World::world.positions[i].x = 0;

            }

            if (World::world.hasComponents[i][IA] &&
                World::world.aabbs[i].x > window.getSize().x - World::world.aabbs[i].w) {

               World::world.aabbs[i].x = window.getSize().x - World::world.aabbs[i].w;
               World::world.positions[i].x = window.getSize().x - World::world.aabbs[i].w;

            }
        }
    }
}
