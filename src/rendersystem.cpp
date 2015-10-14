#include "system.hpp"

RenderSystem::RenderSystem(sf::RenderWindow &window) : 
	mReferenceToWindow(window) {}

void RenderSystem::run() {
	mReferenceToWindow.clear();

    for(auto i(0u); i < World::world.numberEntities; ++i) {

        if(World::world.used[i] &&
           World::world.hasComponents[i][AABB] &&
           World::world.hasComponents[i][SPRITE]) {
            auto sprite = World::world.sprites[i];
            auto aabb = World::world.aabbs[i];

            sprite.image->setPosition(aabb.x, aabb.y);
            mReferenceToWindow.draw(*sprite.image);
        }
    }

	mReferenceToWindow.display();
}
