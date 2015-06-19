#include "../include/rendersystem.hpp"
#include "../include/inputsystem.hpp"
#include "../include/game.hpp"

class MovementSystem : public AbstractSystem {
public:
	MovementSystem() = default;

	void addEntity(std::shared_ptr<Entity> const &entity) override {
		assert(entity->have<Position>());

		mEntities.emplace_back(entity);
	}

	void run() override {
		for(auto &entity : mEntities) {
			if(entity->have<Input>()) {
				auto position = entity->get<Position>();

				position.x += entity->get<Input>().displacement;

				entity->set(position);
			}
		}
	}

	~MovementSystem() = default;

private:
	std::vector<std::shared_ptr<Entity>> mEntities;
};

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Space_Invaders");

	Game game;

	game.addSystem(RENDER_SYSTEM, std::make_unique<RenderSystem>(window));
	game.addSystem(MOVEMENT_SYSTEM, std::make_unique<MovementSystem>());
	game.addSystem(INPUT_SYSTEM, std::make_unique<KeyboardInputSystem>());

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