//
// Created by DCHIQUET on 14/10/2022.
//

#include <iostream>

namespace SolucePrinter
{
    template <typename Type>
    void print(Type T) {
        std::cout << T << std::endl;
    }

    template<typename FirstType, typename... Args>
    void print(FirstType front, Args... args) {
        std::cout << front << std::endl;
        print(args...);
    }
}


namespace printercpp11
{
    template <typename... Args>
    void count(Args... args) {
          std::cout << sizeof...(args) << std::endl;
    }
}

namespace Hope
{
    template <typename FirstType, typename... Args>
    void print(FirstType front, Args... args) {
        std::cout << front << std::endl;
        if constexpr (sizeof...(args) > 0) {
            print(args...);
        }
    }
}


// fold expression
namespace foldExpression
{
    template<typename... Args>
    auto sum(Args... args) {
        return (args + ...);
    }

    void test() {
        std::cout << sum(1, 2, 3, 4, 5) << std::endl;
    }
}

// expension mechanism
template <typename... Args>
void test(Args... args) {
    (std::cout << ... << args);
}