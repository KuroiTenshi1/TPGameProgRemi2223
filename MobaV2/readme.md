# tp1 : HeroT

## Description

Refaire le tp strategy en ajoutant une class hero template avec un style de combat en template

### Exemple
```cpp
using Warrior = Hero<Sword>;
using Mage = Hero<Staff>;

Warrior w;
Mage m;

w.attack(m);
m.attack(w);
```

## Résultat
https://github.com/KuroiTenshi1/TPGameProgRemi2223/blob/2c36addccf66e8e9152ddb8859001e64e5a74d79/MobaV2/Personnage.cpp
```cpp
template <class Style> // template de style de combat
class HeroTemplate : public Personnage {
public:
    HeroTemplate() {
        this->set_styleDeCombat(new Style());
    }
};
```