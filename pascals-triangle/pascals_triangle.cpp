#include "pascals_triangle.h"

using namespace std;

const pascals_triangle::ptriangle_t pascals_triangle::generate_rows(int n) {
    ptriangle_t ptriangle {};
    for (int i = 0; i < n; i++) {
        vector<int> row {};
        for (int j = 0; j <= i; j++) {
            row.push_back(pascals_triangle::binomial(i, j));
        }
        ptriangle.push_back(row);
    }
    return ptriangle;
}
