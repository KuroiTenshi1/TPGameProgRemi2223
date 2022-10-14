//
// Created by DCHIQUET on 14/10/2022.
//

#include <iostream>

struct Int {
};
struct Boolean {
};
struct Text {
};

template<typename ExternalType>
struct MemoryConvertType {
    using InternalType = ExternalType;
};

template<>
struct MemoryConvertType<Int> {
    using type = int;
    static constexpr type
    Zero = 2;
};

template<>
struct MemoryConvertType<Boolean> {
    using type = char;
    static constexpr type
    Zero = 'z';
};

template<>
struct MemoryConvertType<Text> {
    using type = const char *;
    static constexpr type
    Zero = "Welcome traits";
};

template<typename ExternalType>
using MemoryConvertType_t = typename MemoryConvertType<ExternalType>::type;


template<typename ExternalType>
void someMemoryOperations(const ExternalType &object) {
    using InternalType = MemoryConvertType_t<ExternalType>;
    InternalType IType = MemoryConvertType<ExternalType>::Zero;
    std::cout << "type: " << typeid(InternalType).name() << std::endl;
    std::cout << "value: " << IType << std::endl;

}

struct Toto {
};

int main() {
    Int i;
    Boolean b;
    Text t;
    someMemoryOperations<Int>(i);
    someMemoryOperations<Boolean>(b);
    someMemoryOperations<Text>(t);

    //Toto t;
    //someMemoryOperations<Toto>(t);
}