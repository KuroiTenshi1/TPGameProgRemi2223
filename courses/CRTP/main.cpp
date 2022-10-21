//
// Created by DCHIQUET on 21/10/2022.
//


#include <iostream>

template<typename Derived>
class InterfaceCrtp
{
public:
    void Display()
    {
        std::cout << "From interface" << std::endl;
        static_cast<Derived*>(this)->Display();
    }
};

class Derived : public InterfaceCrtp<Derived>
{
public:
    void Display()
    {
        std::cout << "From derived" << std::endl;
    }
};

int main()
{
    Derived d;
    d.Display();
}