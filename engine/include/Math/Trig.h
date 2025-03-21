#pragma once

#include <cmath>

namespace Trig {
    constexpr float Sin(float x) { return std::sin(x); }
    constexpr float Cos(float x) { return std::cos(x); }
    constexpr float Tan(float x) { return std::tan(x); }
    constexpr float ACos(float x) { return std::acos(x); }
    constexpr float ASin(float x) { return std::asin(x); }
}
