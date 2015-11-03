#include "game.hpp"
#include <thread>

sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders", sf::Style::Titlebar | sf::Style::Close);

int main() {
    srand(time(NULL));

    Game game(window);

    game.create();

    static sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);

    while(window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        timeSinceLastUpdate += clock.restart();

        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            game.run();
        }
    }

    return 0;
}
