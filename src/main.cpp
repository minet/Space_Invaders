#include "game.hpp"

sf::RenderWindow window(sf::VideoMode(800, 600), "Space_Invaders", sf::Style::Titlebar | sf::Style::Close);

int main() {
    srand(time(NULL));

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
