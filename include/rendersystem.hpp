#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include "system.hpp"

/**
 * @brief Draw to screen all entities
 * 
 */
class RenderSystem : public AbstractSystem {
public:
	RenderSystem(sf::RenderWindow &window);

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

	~RenderSystem() = default;

private:
	sf::RenderWindow &mReferenceToWindow;
	std::vector<std::shared_ptr<Entity>> mEntities;
};

#endif