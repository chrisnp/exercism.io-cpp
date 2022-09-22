#include "binary_search.h"
#include <cassert>
#include <algorithm>
#include <stdexcept>

using namespace std;

int binary_search::find( vector<int> haystaq, int needle ) {
    assert( is_sorted( haystaq.cbegin(), haystaq.cend() ) );

    int lo {0}, hi = haystaq.size() - 1;
    while( lo <= hi ) {
        int mid = (lo + hi) >> 1;
        if( haystaq.at(mid) == needle )
            return mid;
        else if( haystaq.at(mid) < needle )
            lo = mid + 1;
        else 
            hi = mid - 1;
    }
    throw domain_error("not found");
}
