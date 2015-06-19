#ifndef INPUT_SYSTEM_HPP
#define INPUT_SYSTEM_HPP

#include "system.hpp"

/**
 * @brief This system is used to manage all input in our game
 */
class InputSystem : public AbstractSystem {
public:
	InputSystem() = default;

	/**
	 * @brief Add an entity to this system
	 * @details Implementations use a std::vector
	 * 
	 * @param entity
	 */
	void addEntity(std::shared_ptr<Entity> const &entity) override;

	/**
	 * @brief Execute this system
	 */
	void run() override;

	~InputSystem() = default;

private:
	std::vector<std::shared_ptr<Entity>> mEntities;
};

#endif