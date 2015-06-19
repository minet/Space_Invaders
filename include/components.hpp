#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <string>

enum ComponentType{POSITION, VELOCITY, AABB, SPRITE, EVENT, IA};

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

	T x; //!< Position in x axe
	T y; //!< Position in y axe
};

/**
 * @brief Provide a velocity for an entity
 * 
 */
template<typename T = float>
struct Velocity : public Component {
	T x; //!< Speed in x axe
	T y; //!< Speed in y axe
};

/**
 * @brief Provide a Axis Aligned Bounding Box for an Entity
 * 
 */
template<typename T = float>
struct Aabb : public Component {
	Position<T> &refPosition; //!< If an Entity is move, its bounding box has to be moved as well
	T w; //!< Width of Entity
	T h; //!< Height of Entity
};

/**
 * @brief Provide a Sprite which is drawable for an Entity
 * @details [long description]
 * 
 */
struct Sprite : public Component {
	std::string name; //!< Name of an Entity because : Abstraction
};

/**
 * @brief Provide a simplified Event to manage Entity controlled by Player
 * 
 * @tparam T = float [description]
 */
template<typename T = float>
struct Event : public Component {
	T displacement; // Displacement over the X axis
	bool toShot; // Player want to shot?
};


#endif