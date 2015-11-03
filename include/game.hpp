#ifndef GAME_HPP
#define GAME_HPP

#include "system.hpp"

class Game {
public:
    Game(sf::RenderWindow &window);

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
    RenderSystem mRenderSystem;
    //KeyboardInputSystem mInputSystem;
    VideoInputSystem mInputSystem;
    ApplyInputSystem mApplyInputSystem;
    MovementSystem mMovementSystem;
    CollideSystem mCollideSystem;
    IASystem mIASystem;
};

#endif
