#ifndef WORLD_HPP
#define WORLD_HPP

#include "components.hpp"
#include <vector>
#include <algorithm>
#include <cassert>
#include <bitset>

using Entity = unsigned;

struct World {
    std::vector<Position> positions;
    std::vector<Velocity> velocities;
    std::vector<Aabb> aabbs;
    std::vector<Sprite> sprites;
    std::vector<Input> inputs;
    std::vector<Ia> ias;

    std::vector<bool> used;
    std::vector<std::bitset<NUMBER_COMPONENTS>> hasComponents;
    unsigned numberEntities = 0;

    static World world;
};

Entity createPlayer();
Entity createMissile(float x, float y, bool isPlayer);

#endif
