#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include "StyleDeCombat.hpp"

class Personnage {
private:
    StyleDeCombat *_styleDeCombat;
public:
    ~Personnage() {
        delete this->_styleDeCombat;
    }

    void set_styleDeCombat(StyleDeCombat m_styleDeCombat) {
        delete this->_styleDeCombat;
        this->_styleDeCombat = m_styleDeCombat;
    }

    void attack(Personnage* self, Personnage* Target) {
        _styleDeCombat->Attack(self, Target);
    }

};


// create hero template class with style of combat
template <class Style>
class HeroTemplate : public Personnage {
public:
    HeroTemplate() {
        this->set_styleDeCombat(new Style());
    }
};

#endif 

/*
#ifndef HERO_H
#define HERO_H

#include "Skill.h"

class Weapon;

class Heal;

class Hero {
private:
    Weapon *weapon_;
    Heal *heal_;
public:
    ~Hero() {
        delete this->weapon_;
    }

    void set_weapon(Weapon *weapon) {
        delete this->weapon_;
        this->weapon_ = weapon;
    }

    void set_heal(Heal *heal) {
        delete this->heal_;
        this->heal_ = heal;
    }

    void attack(Hero *self, Hero *Target) {
        weapon_->Attack(Hero *self, Hero *Target);
    }

    void healing(Hero *self, Hero *Target = nullptr) {
        heal_->Healing(self, Target);
    }

};



#endif //HERO_H

*/