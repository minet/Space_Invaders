#include "game.hpp"

sf::RenderWindow window(sf::VideoMode(800, 600), "Space_Invaders", sf::Style::Titlebar | sf::Style::Close);

int main() {
    srand(time(NULL));

   /* cv::VideoCapture v(0);

    if(!v.isOpened())
        return 1;

    cv::Mat pic;
    cv::namedWindow("video", 1);
  */
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
