#include "../include/game.hpp"

World World::world;

using namespace std;

Game::Game(sf::RenderWindow &window) :
    mRenderSystem(window) {}

void Game::create() {
    createPlayer();
}

void Game::run() {
    mRenderSystem.run();
    mInputSystem.run();
    mApplyInputSystem.run();
    mMovementSystem.run();
}
