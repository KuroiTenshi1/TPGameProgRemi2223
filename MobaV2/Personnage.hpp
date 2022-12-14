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

    void attack(Personnage *Target) {
        _styleDeCombat->Attack(this, Target);
    }

};


template<class Fight, class Skill>
class HeroTemplate : public Personnage {
public:
    HeroTemplate() {
        this->set_styleDeCombat(new Style());
    }
};

#endif
