#include "game.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Space_Invaders", sf::Style::Fullscreen);

    Game game(window);

    game.create();

	while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        game.run();
    }

    return 0;
}
