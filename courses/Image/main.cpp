//
// Created by DCHIQUET on 21/10/2022.
//

#include "Image.h"
#include <iostream>

int main() {
    //Image::Image img(10, 10);
    //img(5,5) = 42.f;
    //std::cout << img(5,5) << std::endl;

    Image::Image img(2, 2);
    img(0, 0) = 0.0f;
    img(0, 1) = 1.0f;
    img(1, 0) = 2.5f;
    img(1, 1) = 3.0f;
    std::cout << img(0, 0) << std::endl;
    std::cout << img(0, 1) << std::endl;
    std::cout << img(1, 0) << std::endl;
    std::cout << img(1, 1) << std::endl;


    std::cout << "Before Clamp" << std::endl;
    Image::Clamp clamp(1.0f, 2.0f);
    img = clamp.compute(img);
    std::cout << img(0, 0) << std::endl;
    std::cout << img(0, 1) << std::endl;
    std::cout << img(1, 0) << std::endl;
    std::cout << img(1, 1) << std::endl;

    return 0;
}
