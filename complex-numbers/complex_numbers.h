#pragma once

namespace complex_numbers {

class Complex {
public:
    Complex(double real, double imag);
    auto real() const -> double;
    auto imag() const -> double;
    auto abs() const -> double;
    auto conj() const -> Complex;
    auto exp() const -> Complex;
    auto operator*(const Complex &that) const -> Complex;
    auto operator/(const Complex &that) const -> Complex;
    auto operator+(const Complex &that) const -> Complex;
    auto operator-(const Complex &that) const -> Complex;
private:
    double _Real;
    double _Imag;
};

}  // namespace complex_numbers


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif
