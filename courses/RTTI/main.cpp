#include <iostream>
#include <string>
#include <functional>
#include <map>

using Typename = std::string;

class Rtti {
public:
    Rtti(const Typename& classname, Rtti* parentRtti): m_classname(classname), m_parentRtti(parentRtti) {};
    const Typename& getClassname() const { return m_classname; }
    Rtti* getParentRtti() const { return m_parentRtti; }

private:
    Typename m_classname;
    Rtti* m_parentRtti;
};

class HasRtti {
    virtual Rtti* getInstanceRtti() = 0;
};

class NoAncestors {
public:
    static Rtti* getClassRtti() { return nullptr; };

};

#define DECLARE_RTTI(Classname, ParentType) \
    static Rtti* getClassRtti() { static Rtti theRtti{ #Classname, ParentType::getClassRtti() }; return &theRtti; } \
    virtual Rtti* getInstanceRtti() { return getClassRtti(); }


struct GameObject: public HasRtti {
    DECLARE_RTTI(GameObject, NoAncestors)
};

struct Character : public GameObject {
    DECLARE_RTTI(Character, GameObject)

};

struct Player : public Character {
    DECLARE_RTTI(Player, Character)

};

struct Barbarian : public Player {
    DECLARE_RTTI(Barbarian, Player)

};

struct Wizard : public Player {
    DECLARE_RTTI(Wizard, Player)

};

template <typename... Ts>
struct TypeList {};

template<typename GameObjectType>
struct Renderer;

template<>
struct RendererBarbarian {void render(Barbarian*) {std::cout << "Rendering Barbarian" << std::endl;}};

template<>
struct RendererWizard {void render(Wizard*) {std::cout << "Rendering Wizard" << std::endl;}};

template<template<typename GameObjectType> class FnToDispatch, typename GameObjectTypeList>
class ExternalDispatcher {
};

template<template<typename GameObjectType> class FnToDispatch, typename... GameObjectTypes>
class ExternalDispatcher<FnToDispatch, TypeList<GameObjectTypes...>> {
public:
    void invokeIfRequired(GameObject* go){
        if(go->getInstanceRtti() == GameObjectTypes::getClassRtti()) {
            FnToDispatch<GameObjectTypes> fn;
            fn.render(static_cast<GameObjectTypes*>(go));
        }
    }

    void operator(GameObject* go){

    }
};

void testExternalDispatch(GameObject* go) {
    std::map<Rtti*, std::function<void(GameObject*)>> myMap = {
            {Barbarian::getClassRtti(), [](GameObject* go) { BarbarianRenderer().render(static_cast<Barbarian*>(go)); }},
            {Wizard::getClassRtti(), [](GameObject* go) { WizardRenderer().render(static_cast<Wizard*>(go)); }}
    };

    auto it = myMap.find(go->getInstanceRtti());
    if (it == myMap.end()) {
        throw;
    }
    it->second(go);

}
void test() {
    GameObject* wizard = new Wizard;

    if (wizard->getInstanceRtti() == Wizard::getClassRtti())
        std::cout << "CA MARCHE" << std::endl;

    if (wizard->getInstanceRtti() != Barbarian::getClassRtti())
        std::cout << "CA MARCHE" << std::endl;

    std::cout << wizard->getInstanceRtti()->getClassname() << std::endl;
    std::cout << wizard->getInstanceRtti()->getParentRtti()->getClassname() << std::endl;
    std::cout << wizard->getInstanceRtti()->getParentRtti()->getParentRtti()->getClassname() << std::endl;

}


int main() {
    test();
}