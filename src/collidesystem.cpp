#include "system.hpp"

void CollideSystem::run() {

    for(auto i = 0u; i < World::world.numberEntities; ++i) {

        if (World::world.used[i] &&
            World::world.hasComponents[i][AABB]) {

            if (World::world.aabbs[i].x < 0) {



            }

        }



        }
    }
}
