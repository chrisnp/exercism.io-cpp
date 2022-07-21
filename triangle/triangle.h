#pragma once

#include <vector>

namespace triangle {
    
    enum class flavor {
        equilateral, 
        isosceles,
        scalene
    };

    flavor kind(double, double, double);

}  // namespace triangle

namespace doubles {

    double maximum(std::vector<double>&);
    
    double minimum(std::vector<double>&);
    
    double kahanSum(std::vector<double>&); 

} // namespace doubles

#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif