//
// Created by DCHIQUET on 14/10/2022.
//
#include <iostream>

namespace capabilities {
    struct ICan_fight {
        virtual ~ICan_fight() = default;

        virtual void fight() = 0;
    };

    struct can_fight_with_sword : ICan_fight {
        void fight() override {
            std::cout << "Moi me battre avec ma grosse épée" << std::endl;
        }
    };

    struct can_fly {
        void fly() {
            std::cout << "Moi voler" << std::endl;
        }
    };

    struct can_cast {
        void cast() {
            std::cout << "Moi faire magie" << std::endl;
        }
    };
}

template<typename... Capabilities>
struct Hero : public Capabilities ... {
};

int main() {
    Hero<capabilities::can_fight_with_sword, capabilities::can_cast> h;
    h.fight();
    h.cast();
    return 0;
}