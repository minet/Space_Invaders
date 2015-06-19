#ifndef GAME_HPP
#define GAME_HPP

#include "system.hpp"

class Game {
public:
	Game();

	void addSystem(SystemType type, std::unique_ptr<AbstractSystem> &&system);

	/**
	 * @brief Create game entities with components and add them to systems
	 */
	void create();

	/**
	 * @brief Update the game
	 */
	void run();

	~Game() = default;
private:
	std::vector<std::unique_ptr<AbstractSystem>> mSystems;
};

#endif