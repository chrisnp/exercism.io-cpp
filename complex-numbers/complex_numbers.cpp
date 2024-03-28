#include "complex_numbers.h"
#include <cmath>

namespace complex_numbers {

Complex::Complex(double real, double imag) : _Real(real), _Imag(imag) 
{}

auto Complex::real() const -> double { return _Real; }
auto Complex::imag() const -> double { return _Imag; }

double Complex::abs() const {
  return std::sqrt(_Real * _Real + _Imag * _Imag);
}

Complex Complex::conj() const { return Complex(_Real, -_Imag); }

Complex Complex::exp() const {
  double exp_a = std::exp(_Real);
  return Complex(exp_a * std::cos(_Imag), exp_a * std::sin(_Imag));
}

Complex Complex::operator*(const Complex &that) const {
  return Complex(_Real * that._Real - _Imag * that._Imag,
                 _Imag * that._Real + _Real * that._Imag);
}

Complex Complex::operator/(const Complex &that) const {
  double cd_squared = that._Real * that._Real + that._Imag * that._Imag;
  return Complex((_Real * that._Real + _Imag * that._Imag) / cd_squared,
                 (_Imag * that._Real - _Real * that._Imag) / cd_squared);
}

Complex Complex::operator+(const Complex &that) const {
  return Complex(_Real + that._Real, _Imag + that._Imag);
}

Complex Complex::operator-(const Complex &that) const {
  return Complex(_Real - that._Real, _Imag - that._Imag);
}

}  // namespace complex_numbers
