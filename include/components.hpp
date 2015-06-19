#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <memory>
#include <SFML/Graphics.hpp>

enum ComponentType{POSITION, VELOCITY, AABB, SPRITE, INPUT, IA};

struct Component {
    Component(ComponentType _type) : type(_type){}

    ComponentType type;
};

/**
 * @brief Provide a position for an entity
 * 
 */
struct Position : public Component {
	Position(float _x, float _y) :
		Component(POSITION), x(_x), y(_y) {}

	Position() :
		Component(POSITION) {}

	float x; //!< Position in x axe
	float y; //!< Position in y axe
};

/**
 * @brief Provide a velocity for an entity
 * 
 */
struct Velocity : public Component {
	Velocity(float _x,float _y) :
		Component(VELOCITY), x(_x), y(_y) {}

	Velocity() :
		Component(VELOCITY) {}

	float x; //!< Speed in x axe
	float y; //!< Speed in y axe
};

/**
 * @brief Provide a Axis Aligned Bounding Box for an Entity
 * 
 */
struct Aabb : public Component {
	Aabb(float _x,float _y,float _w, float _h) :
		Component(AABB), x(_x), y(_y), w(_w), h(_h) {}

	Aabb() :
		Component(AABB) {}

	float x; //!< Position in x axe : upper left
	float y; //!< Position in y axe
	float w; //!< Width of Entity
	float h; //!< Height of Entity
};

/**
 * @brief Provide a Sprite which is drawable for an Entity
 * @details [long description]
 * 
 */
struct Sprite : public Component {
	Sprite(std::shared_ptr<sf::Shape> &&_image) : 
		Component(SPRITE), image(_image) {}

	Sprite() : 
		Component(SPRITE) {}

	std::shared_ptr<sf::Shape> image; //!< Pointer to a shape drawable by SFML
};

/**
 * @brief Provide a simplified Input to manage Entity controlled by Player
 * 
 */
struct Input : public Component {
	Input() :
		Component(INPUT), displacement(0.f), toShot(false) {}

	float displacement; // Displacement over the X axis
	bool toShot; // Player wants to shot?
};

/**
 * @brief Provide a simplified IA to manage Ennemies
 * 
 */
struct Ia : public Component {
	Ia() : 
		Component(IA), toShot(false) {}

	bool toShot; // IA wants to shot
};

#endif