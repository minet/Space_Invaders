#include "../include/inputsystem.hpp"

InputSystem::InputSystem(sf::RenderWindow &window) :
	mReferenceToWindow(window) {}

void InputSystem::addEntity(std::shared_ptr<Entity> const &entity) {
	assert(entity->have<Input<float>>());

	mEntities.emplace_back(entity);
}

void InputSystem::run() {
	for(auto &entity : mEntities) {
		auto input = entity->get<Input<float>>();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			input.displacement = -5.f;

		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			input.displacement = 5.f;

		else 
			input.displacement = 0.f;

		entity->set(input);
	}
}