#include "Personnage.hpp"
#include "StyleDeCombat.hpp"

class Warrior : public Personnage {
public:
    Warrior() {
        this->set_styleDeCombat(new Sword());
    }
};

class Mage : public Personnage {
public:
    Mage() {
        this->set_styleDeCombat(new Stick());
    }
};


using MagicianTemplate = HeroTemplate<Stick>;
using WarriorTemplate = HeroTemplate<Sword>;
