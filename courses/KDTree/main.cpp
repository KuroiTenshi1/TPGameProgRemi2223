#include <iostream>
#include <string>
#include <functional>
#include <map>




template <size_t Dimension, typename T>
struct Point {
    static_assert(std::is_pod_v<T>, "T must be a POD type");

    template<typename... Args>
    Point(Args... args) : coordinates{args...} {}

    Point(const Point& point) {
        coordinates = point.coodinates;
    }

    template<size_t Dim, typename Type>
    friend std::ostream& operator<<(std::ostream& os, const Point<Dim, Type>& point){
        os << "(";
        for (auto i = 0; i < Dimension; ++i) {
            os << point.coordinates[i];
            if (i != Dimension - 1) {
                os << ", ";
            }
        }
        os << ")";
    }

    std::array<T, Dimension> coordinates;
};

template <typename ContainerTypeA, typename ContainerTypeB,
        typename ReturnType = std::common_type_t<
                typename ContainerTypeA::value_type,
                typename ContainerTypeB::value_type>>
ReturnType ScalarProduct(const ContainerTypeA& a, const ContainerTypeB& b, ReturnType initValue = 0){
    if(a.size() != b.size())
        throw std::runtime_error("Container sizes must be equal");

    auto itA = a.begin();
    auto itB = b.begin();
    while(itA != a.end()){
        initValue = initValue + (*itA * *itB);
        ++itA;
        ++itB;
    }
    return initValue;
}

template<typename T>
struct KDNode {
    KDNode(const Point<2, T>& point) : point(point) {}

    Point<2, T> point;
    KDNode* left = nullptr;
    KDNode* right = nullptr;
};




int main() {
    return 0;
}