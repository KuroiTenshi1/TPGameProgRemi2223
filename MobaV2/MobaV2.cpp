// MobaV2.cpp : définit le point d'entrée de l'application.
//

#include "MobaV2.h"

using namespace std;

int main() {
    Personnage *p1 = new Warrior();
    Personnage *p2 = new Mage();
    p1->attack(p2);
    p2->attack(p1);
    return 0;
}
