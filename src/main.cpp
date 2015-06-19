#include "../include/rendersystem.hpp"
#include "../include/game.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Space_Invaders");

	Game game;

	game.addSystem(RENDER_SYSTEM, std::make_unique<RenderSystem>(window));
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
