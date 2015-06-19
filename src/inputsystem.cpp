#include "../include/inputsystem.hpp"

void InputSystem::addEntity(std::shared_ptr<Entity> const &entity) {
	assert(entity->have<Input>());

	mEntities.emplace_back(entity);
}

void InputSystem::run() {
	for(auto &entity : mEntities) {
		auto input = entity->get<Input>();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			input.displacement = -0.2f;

		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			input.displacement = 0.2f;

		else 
			input.displacement = 0.f;

		entity->set(input);
	}
}