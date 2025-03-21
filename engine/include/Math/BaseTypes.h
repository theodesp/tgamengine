#pragma once

#include <cmath>
#include <limits>
#include <algorithm>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace Math {

    // Mathematical constants
    constexpr float PI = glm::pi<float>();
    constexpr float TWO_PI = glm::two_pi<float>();

    // Returns the square of a number
    template <typename T>
    constexpr T sqr(T x) { return x * x; }

    // Clamps a value between minVal and maxVal
    template <typename T>
    constexpr T clamp(T val, T minVal, T maxVal) {
        return std::clamp(val, minVal, maxVal);
    }

    // Returns the sign of a number (-1 for negative, 1 for positive, 0 for zero)
    template <typename T>
    constexpr int sign(T x) {
        return (x > 0) - (x < 0);
    }

    // Converts radians to degrees
    constexpr float rad2deg(float rad) { return rad * (180.0f / PI); }
    
    // Converts degrees to radians
    constexpr float deg2rad(float deg) { return deg * (PI / 180.0f); }

    // 2D Coordinate structure
    struct Coord2D {
        float x = 0.0f;
        float y = 0.0f;

        // Returns the length (magnitude) of the vector
        float length() const { return std::sqrt(x * x + y * y); }

        // Normalizes the vector (makes it unit length)
        void normalize() {
            float len = length();
            if (len > std::numeric_limits<float>::epsilon()) {  // Prevent division by zero
                x /= len;
                y /= len;
            }
        }

        // Returns the angle of the vector in radians
        float toAngle() const;
    };

    // Computes the angle of the 2D vector using atan2
    inline float Coord2D::toAngle() const {
        return std::atan2(y, x);
    }

    // 3D Coordinate structure
    struct Coord3D {
        float x = 0.0f, y = 0.0f, z = 0.0f;

        // Returns the length (magnitude) of the vector
        float length() const { return std::sqrt(x * x + y * y + z * z); }

        // Normalizes the vector (makes it unit length)
        void normalize() {
            float len = length();
            if (len > std::numeric_limits<float>::epsilon()) {  // Prevent division by zero
                x /= len;
                y /= len;
                z /= len;
            }
        }

        // Computes the cross product of two 3D vectors
        static Coord3D cross(const Coord3D &a, const Coord3D &b) {
            return {
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x
            };
        }
    };

    // Structure representing an RGB color
    struct RGBColor {
        float red = 0.0f, green = 0.0f, blue = 0.0f;

        // Converts the RGB color to a 24-bit integer (0xRRGGBB format)
        int toInt() const {
            return ((static_cast<int>(red * 255) & 0xFF) << 16) |
                   ((static_cast<int>(green * 255) & 0xFF) << 8) |
                   ((static_cast<int>(blue * 255) & 0xFF));
        }
    };

}  // namespace Math