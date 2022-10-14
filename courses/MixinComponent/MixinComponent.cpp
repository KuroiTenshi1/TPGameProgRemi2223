//
// Created by DCHIQUET on 14/10/2022.
//
#include <iostream>

namespace components {
    struct IInputComponent {
        virtual ~IInputComponent() = default;

        virtual void processInput() = 0;
    };

    struct PlayerInputComponent : IInputComponent {
        void processInput() override {
            std::cout << "process input for player" << std::endl;
        }
    };

    struct IPhysicsComponent {
        virtual ~IPhysicsComponent() = default;

        virtual void updatePhysics() = 0;
    };

    struct PlayerPhysicsComponent : IPhysicsComponent {
        void updatePhysics() override {
            std::cout << "update physics as a player" << std::endl;
        }
    };

    struct IGraphicsComponent {
        virtual ~IGraphicsComponent() = default;

        virtual void render() = 0;
    };

    struct PlayerGraphicsComponent : IGraphicsComponent {
        void render() override {
            std::cout << "render player" << std::endl;
        }
    };
};

struct GameObjectBase
{
    virtual ~GameObjectBase() = default;
    virtual void update() = 0;
};
template<typename... Components>
struct GameObject : public Components ... {
};

template<typename... Components>
struct GameObject : public GameObjectBase, public Components ...
{

private:
    template<typename = std::enable_if_t<std::is_base_of_t<components::IPhysicsComponent, Components> ...>>
    void UpdateT
    {
        this->updatePhysics();
    }
};

int main() {
    using Player = GameObject<components::PlayerInputComponent, components::PlayerPhysicsComponent, components::PlayerGraphicsComponent>;
    Player a;
    a.update();
    return 0;
}