#include "triangle.h"
#include <set>

triangle::flavor triangle::kind(double s1, double s2, double s3) {

    if (doubles::minimum(s1, s2, s3) <= 0) 
        throw std::domain_error("sides cannot be zero or less");
        
    if (2 * doubles::maximum(s1, s2, s3) >= s1 + s2 + s3 ) 
        throw std::domain_error("triangle inequality violated");
    
    int uniq_sides = std::set<double>{s1, s2, s3}.size();
    return static_cast<triangle::flavor>(uniq_sides - 1);
}
