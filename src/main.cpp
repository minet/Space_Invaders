#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>

#include "../include/componentmanager.hpp"

struct PositionComponent : public Component {
    PositionComponent() : Component(POSITION){}

    PositionComponent(int _x, int _y) :
        Component(POSITION), x(_x), y(_y){}

    bool operator==(PositionComponent const &other){
        if(other.x == x && other.y == y)
            return true;
        return false;
    }

    int x, y;
};

// Un sprite est représenté par un caractère
struct SpriteComponent : public Component {
    SpriteComponent() : Component(SPRITE){}

    SpriteComponent(char _c) :
        Component(SPRITE), c(_c){}

    char c;
};

// Un événement est représenté par string représentant une commande
struct EventComponent : public Component {
    EventComponent() : Component(EVENT){}

    EventComponent(std::string const &_command) :
        Component(EVENT), command(_command){}
    std::string command;
};

// Permettra de gérer les différents system
class System {
public:
    System() = default;

    virtual void addEntity(std::shared_ptr<Entity> const &entity) = 0;

    virtual void run() = 0;

    virtual ~System() = default;

protected:
    std::vector<std::shared_ptr<Entity>> mEntities;
};

// Gère le déplacement
class PhysicSystem : public System {
public:
    PhysicSystem() {}

    // Vérifie que l'entité est conforme au sytème et l'ajoute au tableau
    void addEntity(std::shared_ptr<Entity> const &entity) {
        // Il doit y avoir une position
        assert(entity->have<PositionComponent>());

        mEntities.emplace_back(entity);
    }

    void run() {
        for(auto &entity : mEntities) {
            // Si il y a événement alors on peut mettre à jour
            if(entity->have<EventComponent>()) {
                auto position = entity->get<PositionComponent>();
                auto event = entity->get<EventComponent>();

                if(event.command == "droite")
                    ++position.x;

                else if(event.command == "gauche")
                    --position.x;

                else if(event.command == "haut")
                    --position.y;

                else if(event.command == "bas")
                    ++position.y;

                // Maintenant on test si il n'y a pas d'obstacle
                auto condition = [&position](std::shared_ptr<Entity> &entity) {
                    return entity->get<PositionComponent>() == position;
                };

                // Si aucune entité est à la place de la nouvelle position on peut déplacer
                if(std::find_if(std::begin(mEntities), std::end(mEntities), condition) == std::end(mEntities))
                    entity->set<PositionComponent>(position);
            }
        }
    }
};

// Gère le Rendu
class RenderSystem : public System {
public:
    RenderSystem() = default;

    // Vérifie que l'entité est conforme au sytème et l'ajoute au tableau
    void addEntity(std::shared_ptr<Entity> const &entity) {
        // Doit avoir une position et un sprite
        assert(entity->have<PositionComponent>());
        assert(entity->have<SpriteComponent>());

        mEntities.emplace_back(entity);
    }

    void run() {
        for(auto &line : mMap)
            for(auto &c : line)
                c = 'O';

        for(auto &entity : mEntities) {
            auto position = entity->get<PositionComponent>();
            auto sprite = entity->get<SpriteComponent>();

            mMap[position.y][position.x] = sprite.c;
        }

        // On affiche la map
        for(auto &line : mMap) {
            for(auto &c : line)
                std::cout << c;
            std::cout << "\n";
        }
    }

private:
    char mMap[5][5];
};

// Gère les évenement
class EventSystem : public System {
public:
    EventSystem() = default;

    // Vérifie que l'entité est conforme au sytème et l'ajoute au tableau
    void addEntity(std::shared_ptr<Entity> const &entity) {
        // Doit avoir des événements
        assert(entity->have<EventComponent>());

        mEntities.emplace_back(entity);
    }

    void run() {
        for(auto &entity : mEntities) {
            std::string command;
            std::cin >> command;

            entity->set<EventComponent>(command);
        }
    }
};

std::shared_ptr<Entity> make_character(int x, int y) {
    auto entity = std::make_shared<Entity>();

    entity->add<PositionComponent>(x, y);
    entity->add<SpriteComponent>('P');

    return entity;
}

std::shared_ptr<Entity> make_tree(int x, int y) {
    auto entity = std::make_shared<Entity>();

    entity->add<PositionComponent>(x, y);
    entity->add<SpriteComponent>('A');

    return entity;
}

std::shared_ptr<Entity> make_stone(int x, int y) {
    auto entity = std::make_shared<Entity>();

    entity->add<PositionComponent>(x, y);
    entity->add<SpriteComponent>('R');

    return entity;
}

class Jeu {
public :
    Jeu() {
        auto renderSystem = std::make_unique<RenderSystem>();
        auto physicSystem = std::make_unique<PhysicSystem>();
        auto eventSystem = std::make_unique<EventSystem>();

        auto perso = make_character(2, 2);
        auto arbre = make_tree(2, 3);
        auto rocher = make_stone(1, 1);

        perso->add<EventComponent>(); // Ce perso est gérer par les événements

        renderSystem->addEntity(perso);
        renderSystem->addEntity(arbre);
        renderSystem->addEntity(rocher);

        physicSystem->addEntity(perso);
        physicSystem->addEntity(arbre);
        physicSystem->addEntity(rocher);

        eventSystem->addEntity(perso);

        mSystems.emplace_back(std::move(eventSystem));
        mSystems.emplace_back(std::move(physicSystem));
        mSystems.emplace_back(std::move(renderSystem));
    }

    void run() {
        int i = 4;

        mSystems[2]->run();

        while(i--)
            for(auto &system : mSystems)
                system->run();
    }

private :
    std::vector<std::unique_ptr<System>> mSystems;
};

int main() {
    Jeu jeu;

    jeu.run();

    return 0;
}
