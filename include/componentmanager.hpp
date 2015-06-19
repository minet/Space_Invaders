#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP

#include "components.hpp"

/**
 * @brief Let to Manage all components of an Entity
 * @return [description]
 */
class ComponentManager {
public:

    /**
     * @brief Let to get the component represented by Component Type
     * 
     * @tparam T Component Type	
     * @return The component
     */
    template<typename T>
    T get() {
        return *static_cast<T*>(getIteratorOfComponent<T>()->get());
    }

    /**
     * @brief Let to set the component represented by Component Type
     * 
     * @tparam T Component Type	
     */
    template<typename T>
    void set(T const &value) {
        *static_cast<T*>(getIteratorOfComponent<T>()->get()) = value;
    }

	/**
     * @brief Let to set the component represented by Component Type
     * 
     * @tparam T Component Type	
     */
    template<typename T, typename ...Args>
    void set(Args &&...args) {
       *static_cast<T*>(getIteratorOfComponent<T>()->get()) = T(std::forward<Args>(args)...);
    }

    /**
     * @brief Let to know if the Entity has this component represented by Component Type
     * 
     * @tparam T Component Type
     * @return true if it has, false else
     */
    template<typename T>
    bool have() {
        return getIteratorOfComponent<T>() != std::end(mComponents);
    }

    /**
     * @brief Add an Component Type to the Entity
     * @details assertion if Entity already has this Component
     * 
     * @param args Arguments to build Component
     */
    template<typename T, typename ...Args>
    void add(Args &&...args) {
    	assert(!this->have<T>());
        mComponents.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

private:
	/**
	 * @brief Let to get the iterator of Component
	 * 
	 * @return iterator on the std::unique_ptr<Component> pointing on Component Type
	 */
    template<typename T>
    std::vector<std::unique_ptr<Component>>::iterator getIteratorOfComponent() {
        auto condition = [](std::unique_ptr<Component> &component) {
            if(component->type == T().type)
                return true;
            return false;
        };

        auto it = std::find_if(std::begin(mComponents), std::end(mComponents), condition);
        return it;
    };

    std::vector<std::unique_ptr<Component>> mComponents; //!< Components owned by Entity
};

using Entity = ComponentManager;

#endif