#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "componentmanager.hpp"

enum SystemType{INPUT_SYSTEM, IA_SYSTEM, ACTION_TO_SHOT_SYSTEM, MOVEMENT_SYSTEM, COLLIDER_SYSTEM, RENDER_SYSTEM, NUMBER_OF_SYSTEMS};

/**
 * @brief Simple System to manage entities in our game
 * 
 */
class AbstractSystem {
public:
	/**
	 * @brief Add an entity to this system
	 * @details Implementations for addEntity is let to the user choice, it could be use assertion to avoid mistake
	 * 
	 * @param entity
	 */
	virtual void addEntity(std::shared_ptr<Entity> const &entity) = 0;

	/**
	 * @brief Execute this system
	 */
	virtual void run() = 0;
	virtual ~AbstractSystem() = default;
};

#endif