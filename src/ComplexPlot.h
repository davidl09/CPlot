//
// Created by davidl09 on 11/6/23.
//

#ifndef IMGUI_TEST2_COMPLEXPLOT_H
#define IMGUI_TEST2_COMPLEXPLOT_H

#include <vector>
#include <complex>
#include <mutex>

#include "Pixel.h"

class ComplexPlot {
public:
    ComplexPlot (int width, int height) noexcept;

    auto begin();

    auto end();

    auto size();

    void resize(int newWidth, int newHeight);

    constexpr std::pair<double, double> getXYFromDistance(const auto& iter) const {
        int distFromBegin = std::distance(data.begin(), iter);
        double pixelPerUnit = y_range / static_cast<double>(height);
        double x_range = y_range * (static_cast<double>(height) / static_cast<int>(width));

        size_t pixDistFromLeft = distFromBegin % height;
        size_t pixDistFromTop = distFromBegin / height;
    }

    template<typename T> //T must be floating point
    static constexpr Pixel cmplxToRgb(std::complex<T> num)
    {
        T mag = std::abs(num), arg = std::arg(num);
        mag = -5.0/(mag + 5) + 1;
        Pixel result{};
        for(int i : {RED, GREEN, BLUE}) {
            result[i] = (unsigned char)(mag*(127.5*sin(arg + (std::numbers::pi * i) / 2) + 127.5));
        }
        return result;
    }

private:
    std::vector<Pixel> data;
    double y_range; //
    double x_offset, y_offset;
    size_t width, height;

};


#endif //IMGUI_TEST2_COMPLEXPLOT_H
