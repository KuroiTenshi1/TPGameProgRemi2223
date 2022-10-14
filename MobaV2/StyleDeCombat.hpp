#ifndef STYLEDECOMBAT_HPP
#define STYLEDECOMBAT_HPP

#include "Personnage.hpp"
#include <iostream>

class StyleDeCombat {
public:
    virtual ~StyleDeCombat() {}
    virtual void Attack(Personnage* self, Personnage* Target) const = 0;
};


#endif 
