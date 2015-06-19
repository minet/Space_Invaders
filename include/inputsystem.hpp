#ifndef INPUT_SYSTEM_HPP
#define INPUT_SYSTEM_HPP

#include "system.hpp"

class InputSystem : public AbstractSystem {
public:
	InputSystem(sf::RenderWindow &window);

	void addEntity(std::shared_ptr<Entity> const &entity) override;
	void run() override;

	~InputSystem() = default;

private:
	sf::RenderWindow &mReferenceToWindow;
	std::vector<std::shared_ptr<Entity>> mEntities;
};

#endif