#include <iostream>
#include <memory>

template<typename... Args>
struct typelist{};

// IsEmpty

template<typename List>
struct is_empty{
    static constexpr bool value = true;
};

template<>
struct is_empty<typelist<>>{
    static constexpr bool value = true;
};

template<typename List>
static constexpr bool is_empty_v = is_empty<List>::value;

// If_Then_Else

template <bool Condition, typename TrueType, typename FalseType>
struct if_then_else;

template <typename TrueType, typename FalseType>
struct if_then_else<true, TrueType, FalseType>
{
    using type = TrueType;
};

template <typename TrueType, typename FalseType>
struct if_then_else<false, TrueType, FalseType>
{
    using type = FalseType;
};

template <bool Condition, typename TrueType, typename FalseType>
using if_then_else_t = typename if_then_else<Condition, TrueType, FalseType>::type;

// FRONT

template<typename List>
struct front;

template<typename Head, typename... Tail>
struct front<typelist<Head, Tail...>>{
    using type = Head;
};

template<typename List>
using front_t = typename front<List>::type;

// POP_FRONT

template<typename List>
struct pop_front;

template<typename Head, typename... Tail>
struct pop_front<typelist<Head, Tail...>>{
    using type = typelist<Tail...>;
};

template<typename List>
using pop_front_t = typename pop_front<List>::type;

// contains

template<typename List, typename Type, bool IsEmpty = is_empty_v<List>>
struct contains;

template<typename List, typename Type>
struct contains<List, Type, true> : std::integral_constant<bool, false>{};

template<typename List, typename Type>
struct contains<List, Type, false> : if_then_else_t<
        std::is_same_v<front_t<List>, Type>,
        std::integral_constant<bool, true>,
        contains<pop_front_t<List>, Type>
>{};

template<typename List, typename Type>
static constexpr bool contains_v = contains<List, Type>::value;

// factory

template <typename... Types>
struct Factory{

    using list = typelist<Types...>;


    template<typename Type>
    struct Creator
    {
        static_assert(!contains_v<list, Type>);
        using type = Type;
    };


    template<typename Type, typename... Args>
    static std::unique_ptr<Type>create(Args... args){
        return std::unique_ptr<Type>(new typename Creator<Type>::type(args...));
    }
};

class Player;
class Enemy;

using AvailuableTypes = typelist<Player,Enemy>;

class GameObject{
public:
    std::string name;

    virtual ~GameObject(){};

};

class Player : public GameObject{
    friend struct Factory<AvailuableTypes>;
private:
    std::string name;

    Player(){
        name = "player";
    }
};

class Enemy : public GameObject{
    friend struct Factory<AvailuableTypes>;
private:
    std::string name;

    Enemy(){
        name = "Enemy";
    }
};

using GameObjectFactory = Factory<AvailuableTypes>;

int main(){

    const auto player = GameObjectFactory::create<int>();
    //std::cout << Player << std::endl;
    return 0;
}