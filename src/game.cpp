#include "../include/game.hpp"

Game::Game() :
	mSystems(NUMBER_OF_SYSTEMS) {}

void Game::addSystem(SystemType type, std::unique_ptr<AbstractSystem> &&system) {
	mSystems[type] = std::move(system);
}

void Game::create() {
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();

	auto sprite = std::make_shared<sf::RectangleShape>(sf::Vector2f(120, 50));
	sprite->setFillColor(sf::Color(255, 127, 63, 255));

	entity->add<Position>(375, 50);
	entity->add<Input>();
	entity->add<Sprite>(sprite);

	mSystems[RENDER_SYSTEM]->addEntity(entity);
	mSystems[MOVEMENT_SYSTEM]->addEntity(entity);
	mSystems[INPUT_SYSTEM]->addEntity(entity);
}

void Game::run() {
	for(auto &system : mSystems)
		if(system != nullptr)
			system->run();
}