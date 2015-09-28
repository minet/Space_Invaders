#include "world.hpp"

using namespace std;

Entity searchGoodPlaceForEntities() {
    Entity i(0u);
    for(; i < World::world.numberEntities; ++i) {
        if(World::world.used[i] == false)
            break;
    }

    return i;
}

void createEntity(Entity number) {
    if(number < World::world.numberEntities)
        World::world.used[number] = true;

    else {
        ++World::world.numberEntities;
        World::world.used.emplace_back(true);
        World::world.hasComponents.emplace_back(bitset<NUMBER_COMPONENTS>());
        World::world.positions.emplace_back();
        World::world.velocities.emplace_back();
        World::world.aabbs.emplace_back();
        World::world.sprites.emplace_back();
        World::world.inputs.emplace_back();
        World::world.ias.emplace_back();
    }
}

Entity createPlayer() {
    auto sprite = std::make_shared<sf::RectangleShape>(sf::Vector2f(120, 50));
    sprite->setFillColor(sf::Color(255, 127, 63, 255));

    Entity entity = searchGoodPlaceForEntities();

    createEntity(entity);

    World::world.hasComponents[entity][POSITION] = true;
    World::world.hasComponents[entity][SPRITE] = true;
    World::world.hasComponents[entity][VELOCITY] = true;
    World::world.hasComponents[entity][INPUT] = true;
    World::world.hasComponents[entity][AABB] = true;

    World::world.positions[entity] = Position(400, 550);
    World::world.sprites[entity] = Sprite(sprite);
    World::world.aabbs[entity] = Aabb(World::world.positions[entity].x, World::world.positions[entity].y,
                                      sprite->getSize().x, sprite->getSize().y);

    return entity;
}

Entity createMissile(float x, float y, bool isPlayer) {
    static auto sprite(std::make_shared<sf::RectangleShape>(sf::Vector2f(5, 15)));
    sprite->setFillColor(sf::Color(255, 255, 255, 255));

    Entity entity = searchGoodPlaceForEntities();

    createEntity(entity);

    World::world.hasComponents[entity][POSITION] = true;
    World::world.hasComponents[entity][SPRITE] = true;
    World::world.hasComponents[entity][VELOCITY] = true;
    World::world.hasComponents[entity][AABB] = true;


    World::world.positions[entity] = Position(x - sprite->getSize().x / 2, y - sprite->getSize().y);
    World::world.sprites[entity] = Sprite(sprite);
    World::world.velocities[entity] = Velocity(0, isPlayer ? -1.f : 1.f);

    return entity;
}