//
// Created by DCHIQUET on 21/10/2022.
//


#include <iostream>
#include <vector>


void process(int &value){
    //    std::cout<< "hello 1 : " << it  << std::endl;
    value *= value;
}

#include <cmath>
struct Process{
    void operator()(int& value)const{
        value = std::sqrt(value);
    }
};


template <typename Iterator, typename Callable>
void execute (Iterator valueBegin, Iterator valueEnd, Callable operation){
    for (auto it = valueBegin; it != valueEnd; ++it){
        operation(*it);
    }
}

template<typename Iterator,typename Callable, typename... Args>
void executeInvoke(Iterator begin, Iterator end, Callable operation, const Args&... args) {
    for (auto it = begin; it != end; ++it) {
        operation(*it, args...);
    }
}

void display(std::vector<int> values){
    for(int i = 0; i < values.capacity(); ++i)
    {
        std::cout << values.at(i)<< std::endl;
    }
}

struct ProcessMember{
    void sqrt(int& value){
        value = std::sqrt(value);
    }
};

int main() {
    std::vector<int> values = {2, 10, 8, 7, 9, 3};
    /*
    // compute the square of the values
    execute(values.begin(), values.end(), process);
    // compute the square of the values
    execute(values.begin(), values.end(), &process);
    //compute the square root of the values
    execute(values.begin(), values.end(), Process());

     */

    executeInvoke(values.begin(), values.end(), process);
    display(values);

    executeInvoke(values.begin(), values.end(), &process);
    display(values);

/*
    ProcessMember pm;
    executeInvoke(values.begin(), values.end(), &ProcessMember::sqrt, pm);
    display(values);
*/





}