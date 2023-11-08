//
// Created by davidl09 on 11/6/23.
//

#include "ComplexPlot.h"



void ComplexPlot::resize(int newWidth, int newHeight) {
    data.resize(newWidth * newHeight);
}

auto ComplexPlot::begin() {
    return data.begin();
}

auto ComplexPlot::end() {
    return data.end();
}

auto ComplexPlot::size() {
    return data.size();
}


ComplexPlot::ComplexPlot(int width, int height) noexcept
: width(width), height(height), y_range(10.0), x_offset(width / 2.0), y_offset(height / 2.0) {}

