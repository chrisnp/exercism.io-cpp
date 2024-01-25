#include "series.h"
#include <stdexcept>

using namespace std;

vector<string> series::slice(string const &input, uint_t slice_size) {
    if ( slice_size <= 0)
        throw domain_error("enigmatic error for not actually slicing");
    uint_t input_size = input.length();
    if ( input_size < slice_size ) 
        throw domain_error("cannot slice a string shorter than the slicesize");
    vector<string> slices {};
    for ( uint_t i = 0; i <= input_size - slice_size; ++i ) {
        slices.push_back(input.substr(i, slice_size));
    }  
    return slices;
}