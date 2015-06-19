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
 * @tparam T Type used
 */
template<typename T = float>
struct Position : public Component {
	Position(T const &_x, T const &_y) :
		Component(POSITION), x(_x), y(_y) {}

	Position() :
		Component(POSITION) {}

	T x; //!< Position in x axe
	T y; //!< Position in y axe
};

/**
 * @brief Provide a velocity for an entity
 * 
 */
template<typename T = float>
struct Velocity : public Component {
	Velocity(T const &_x, T const &_y) :
		Component(VELOCITY), x(_x), y(_y) {}

	Velocity() :
		Component(VELOCITY) {}

	T x; //!< Speed in x axe
	T y; //!< Speed in y axe
};

/**
 * @brief Provide a Axis Aligned Bounding Box for an Entity
 * 
 */
template<typename T = float>
struct Aabb : public Component {
	Aabb(Position<T> const &_refPosition, T const _w, T const _h) :
		Component(AABB), refPosition(_refPosition), w(_w), h(_h) {}

	Aabb() : Component(AABB), refPosition(Position<T>()) {}

	Position<T> const &refPosition; //!< If an Entity is move, its bounding box has to be moved as well
	T w; //!< Width of Entity
	T h; //!< Height of Entity
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
 * @tparam T = float [description]
 */
template<typename T = float>
struct Input : public Component {
	Input() :
		Component(INPUT), displacement(T(0)), toShot(false) {}

	T displacement; // Displacement over the X axis
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