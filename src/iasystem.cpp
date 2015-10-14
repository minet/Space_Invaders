#include "system.hpp"

bool AnEnnemyIsUnder(Entity i) {
    bool ennemyisunder = false;
    for (auto j(0u); j < World::world.numberEntities;++j) {
        if (World::world.used[j] &&
            World::world.hasComponents[j][IA] &&
            !ennemyisunder && (j!=i)) {

            ennemyisunder = (World::world.aabbs[i].y < World::world.aabbs[j].y) &&
                            (World::world.aabbs[i].x <= World::world.aabbs[j].x + 2 &&
                             World::world.aabbs[i].x >= World::world.aabbs[j].x -2);

       }
    }
    return ennemyisunder;
}

void IASystem::run() {
    static auto clock = sf::Clock();
    int r;

    if(clock.getElapsedTime().asMilliseconds() > 1000) {

        for(auto i(0u); i < World::world.numberEntities; ++i) {
            if (World::world.used[i] &&
                World::world.hasComponents[i][IA]) {

                if (!AnEnnemyIsUnder(i)) {
                    r = rand()%10;
                    if (r == 0)
                    createMissile(World::world.aabbs[i].x + World::world.aabbs[i].w / 2, World::world.aabbs[i].y + World::world.aabbs[i].h + 20, false);
                }
            }
        }
        clock.restart();
    }
}
