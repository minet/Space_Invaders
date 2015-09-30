#include "system.hpp"

bool AnEnnemyIsUnder(Entity i) {
    bool ennemyisunder = false;
    for (auto j(0u); j < World::world.numberEntities;++j) {
        if (World::world.used[j] &&
            World::world.hasComponents[j][IA] &&
            World::world.hasComponents[j][POSITION] &&
            !ennemyisunder &&
            (j!=i)) {

            ennemyisunder = (World::world.positions[i].y < World::world.positions[j].y);

       }
    }
    return ennemyisunder;
}

void IASystem::run() {
    static auto clock = sf::Clock();

    if(clock.getElapsedTime().asMilliseconds() > 800) {

        for(auto i(0u); i < World::world.numberEntities; ++i) {
            if (World::world.used[i] &&
                World::world.hasComponents[i][IA] &&
                World::world.hasComponents[i][POSITION]) {

                if (!AnEnnemyIsUnder(i)) {
                    createMissile(World::world.positions[i].x + 10 , World::world.positions[i].y + World::world.aabbs[i].h + 2, false);
                }
            }
        }
        clock.restart();
    }
}
