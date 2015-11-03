#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "world.hpp"
#include <thread>
//#include <opencv/cv.hpp>

extern sf::RenderWindow window;

/**
 * @brief Draw to screen all entities
 *
 */
class RenderSystem {
public:
    RenderSystem(sf::RenderWindow &window);

    /**
     * @brief Execute this system
     */
    void run();

    ~RenderSystem() = default;

private:
    sf::RenderWindow &mReferenceToWindow;
};

/**
 * @brief This system is used to manage all input in our game
 */
class KeyboardInputSystem {
public:
    KeyboardInputSystem() = default;

    /**
     * @brief Execute this system
     */
    void run();

    ~KeyboardInputSystem() = default;
};

class VideoInputSystem {
public:
    VideoInputSystem();
    
    void run();
    
    ~VideoInputSystem();

private:
    volatile bool mIsRunning = true;
    volatile bool mEnabled = false;
    volatile float mDisplacement = 0.0;
    std::thread mThread;

    void treatEvent();
};

class ApplyInputSystem {
public:
    ApplyInputSystem() = default;

    void run();

    ~ApplyInputSystem() = default;
};

class MovementSystem {
public:
    MovementSystem() = default;

    void run();

    ~MovementSystem() = default;
};

class CollideSystem {
public:
    CollideSystem() = default;

    void run();

    ~CollideSystem() = default;
};

class IASystem {
public:
    IASystem() = default;

    void run();

    ~IASystem() = default;
};

#endif
