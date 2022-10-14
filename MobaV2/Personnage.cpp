#include "Personnage.hpp"
#include "StyleDeCombat.hpp"

// create warrior class with sword style of combat

class Warrior : public Personnage {
public:
    Warrior() {
        this->set_styleDeCombat(new Sword());
    }
};

// create mage class with stick style of combat

class Mage : public Personnage {
public:
    Mage() {
        this->set_styleDeCombat(new Stick());
    }
};




using MagicianTemplate = HeroTemplate<Stick>;
using WarriorTemplate = HeroTemplate<Sword>;
