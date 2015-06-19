#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include "system.hpp"

/**
 * @brief Let to draw to screen all entities
 * 
 */
class RenderSystem : public AbstractSystem {
public:
	RenderSystem(sf::RenderWindow &window);

	void addEntity(std::shared_ptr<Entity> const &entity) override;
	void run() override;	

	~RenderSystem() = default;

private:
	sf::RenderWindow &mReferenceToWindow;
	std::vector<std::shared_ptr<Entity>> mEntities;
};

#endif