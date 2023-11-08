//
// Created by davidl09 on 11/6/23.
//

#ifndef IMGUI_TEST2_PIXEL_H
#define IMGUI_TEST2_PIXEL_H

#include <array>

enum Colours : int {
    RED,
    GREEN,
    BLUE
};


struct Pixel {
    auto &operator[](auto colour){
        return values[colour];
    }

    std::array<unsigned char, 3> values;
};



#endif //IMGUI_TEST2_PIXEL_H
