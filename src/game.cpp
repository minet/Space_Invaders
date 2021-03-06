#include "../include/game.hpp"

World World::world;

using namespace std;

Game::Game(sf::RenderWindow &window) :
    mRenderSystem(window) {}

void Game::create() {
    createPlayer();

    for(auto y(0); y < 4; ++y)
        for(auto x(0); x < 4; ++x)
            createEnnemy(25 * (x + 1), 25 * (y + 1));
}

void Game::run() {
        mInputSystem.run();
        mIASystem.run();
        mApplyInputSystem.run();
        mMovementSystem.run();
        mCollideSystem.run();
        mRenderSystem.run();
}
