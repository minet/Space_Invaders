#include "system.hpp"

RenderSystem::RenderSystem(sf::RenderWindow &window) : 
	mReferenceToWindow(window) {}

void RenderSystem::run() {
	mReferenceToWindow.clear();

    for(auto i(0u); i < World::world.numberEntities; ++i) {

        if(World::world.used[i] &&
           World::world.hasComponents[i][POSITION] &&
           World::world.hasComponents[i][SPRITE]) {
            auto position = World::world.positions[i];
            auto sprite = World::world.sprites[i];

            sprite.image->setPosition(position.x, position.y);
            mReferenceToWindow.draw(*sprite.image);
        }
    }

	mReferenceToWindow.display();
}
