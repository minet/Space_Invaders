#include "system.hpp"

void CollideSystem::run() {

    bool hasbeeninverted = false;

    for(auto i = 0u; i < World::world.numberEntities; ++i) {

        if (World::world.used[i] &&
            World::world.hasComponents[i][AABB] &&
            World::world.hasComponents[i][POSITION]) {

            if (World::world.hasComponents[i][INPUT]) {

              if (World::world.aabbs[i].x < 0) {

                  World::world.aabbs[i].x = 0;
                  World::world.positions[i].x = 0;
               }

               if (World::world.aabbs[i].x > window.getSize().x - World::world.aabbs[i].w) {

                  World::world.aabbs[i].x = window.getSize().x - World::world.aabbs[i].w;
                  World::world.positions[i].x = window.getSize().x - World::world.aabbs[i].w;
               }
            }


            if (World::world.hasComponents[i][IA]) {

                if ( (World::world.aabbs[i].x < 0 ||
                    World::world.aabbs[i].x > window.getSize().x - World::world.aabbs[i].w) &&
                    !hasbeeninverted) {

                    hasbeeninverted = true;
                    for (auto j = 0u; j < World::world.numberEntities;j++) {
                       if (World::world.hasComponents[j][IA] &&
                           World::world.hasComponents[j][VELOCITY]) {
                             World::world.velocities[j].x *= -1;
                             World::world.positions[j].y += 50;
                       }
                    }
                }
            }

//            for (auto k = 0u; k < World::world.numberEntities;k++) {
 //              if (k!=i && ) {

   //             }
     //       }
        }
    }
}


bool Iscolliding() {

}
