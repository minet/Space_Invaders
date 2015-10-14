#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <memory>
#include <SFML/Graphics.hpp>

enum ComponentType{VELOCITY, AABB, SPRITE, INPUT, IA, NUMBER_COMPONENTS};

/**
 * @brief Provide a velocity for an entity
 * 
 */
struct Velocity {
    Velocity(float _x,float _y) :
        x(_x), y(_y) {}

    Velocity() {}

    float x = 0.f; //!< Speed in x axe
    float y = 0.f; //!< Speed in y axe
};

/**
 * @brief Provide a Axis Aligned Bounding Box for an Entity
 * 
 */
struct Aabb {
	Aabb(float _x,float _y,float _w, float _h) :
        x(_x), y(_y), w(_w), h(_h) {}

    Aabb() {}

    float x = 0.0f; //!< Position in x axe : upper left
    float y = 0.0f; //!< Position in y axe
    float w = 0.0f; //!< Width of Entity
    float h = 0.0f; //!< Height of Entity
};

/**
 * @brief Provide a Sprite which is drawable for an Entity
 * @details [long description]
 * 
 */
struct Sprite {
	Sprite(std::shared_ptr<sf::Shape> &&_image) : 
        image(_image) {}

    Sprite() {}

	std::shared_ptr<sf::Shape> image; //!< Pointer to a shape drawable by SFML
};

/**
 * @brief Provide a simplified Input to manage Entity controlled by Player
 * 
 */
struct Input {
    Input() :
        displacement(0.f), toShot(false) {}

	float displacement; // Displacement over the X axis
	bool toShot; // Player wants to shot?
};

/**
 * @brief Provide a simplified IA to manage Ennemies
 * 
 */
struct Ia {
	Ia() : 
        toShot(false) {}

    float displacement; // Displacement over the X axis
	bool toShot; // IA wants to shot
};

#endif
