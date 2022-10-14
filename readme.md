# projets c++ des cours de gameProg jeux vidéo

## 1. tp 1
Refaire le tp strategy en ajoutant une class hero template avec un style de combat en template
exemple 
```cpp
using Warrior = Hero<Sword>;
using Mage = Hero<Staff>;

Warrior w;
Mage m;

w.attack(m);
m.attack(w);
```