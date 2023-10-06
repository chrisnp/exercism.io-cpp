#include "pascals_triangle.h"

namespace pascals_triangle {
using namespace std;

const ptriangle_t generate_rows(int n) {
    ptriangle_t ptriangle {};
    for (int i = 0; i < n; i++) {
        vector<int> row {};
        for (int j = 0; j <= i; j++) {
            row.push_back(binomial(i, j));
        }
        ptriangle.push_back(row);
    }
    return ptriangle;
}
}  // namespace pascals_triangle 



