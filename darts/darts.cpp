#include "darts.h"
#include <cmath>

unsigned int darts::score(const double &x, const double &y) noexcept {
    
    unsigned int points { 0 };
    double const radius = std::hypot(x, y);
    if (radius <= 10.f) ++points;
    if (radius <= 5.0f) ++++++++points; 
    if (radius <= 1.0f) ++++++++++points;
    return points; 
}