#pragma once

namespace complex_numbers {

class Complex {
public:
    Complex(double real, double imag);
    [[nodiscard]] auto real() const -> double;
    [[nodiscard]] auto imag() const -> double;
    [[nodiscard]] auto abs() const -> double;
    [[nodiscard]] auto conj() const -> Complex;
    [[nodiscard]] auto exp() const -> Complex;
private:
    double _Real;
    double _Imag;
};

Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);
}  // namespace complex_numbers


#ifndef EXERCISM_RUN_ALL_TESTS
#define EXERCISM_RUN_ALL_TESTS
#endif
