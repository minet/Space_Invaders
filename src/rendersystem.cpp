#include "../include/rendersystem.hpp"

RenderSystem::RenderSystem(sf::RenderWindow &window) : 
	mReferenceToWindow(window) {}

void RenderSystem::addEntity(std::shared_ptr<Entity> const &entity) {
	assert(entity != nullptr);
	assert(entity->have<Position<float>>());
	assert(entity->have<Sprite>());

	mEntities.emplace_back(entity);
}

void RenderSystem::run() {
	mReferenceToWindow.clear();
	
	for(auto &entity : mEntities) {
		auto position = entity->get<Position<float>>();
		auto sprite = entity->get<Sprite>();

		sprite.image->setPosition(position.x, position.y);
		mReferenceToWindow.draw(*sprite.image);
	}

	mReferenceToWindow.display();
}