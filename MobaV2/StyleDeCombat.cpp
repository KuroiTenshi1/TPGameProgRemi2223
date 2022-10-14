#include "StyleDeCombat.hpp"


class Stick : public StyleDeCombat {
public:
    void Attack(Personnage *self, Personnage *Target) const override;
};

void Stick::Attack(Personnage *self, Personnage *Target) const {
    std::cout << "Attack with stick" << std::endl;
}

class Sword : public StyleDeCombat {
public:
    void Attack(Personnage *self, Personnage *Target) const override;
};

void Sword::Attack(Personnage *self, Personnage *Target) const {
    std::cout << "Attack with stick" << std::endl;
}

class DoubleSword : public StyleDeCombat {
public:
    void Attack(Personnage *self, Personnage *Target) const override;
};

void DoubleSword::Attack(Personnage *self, Personnage *Target) const {
    Sword s{};
    s.Attack(self, Target);
    s.Attack(self, Target);
}
