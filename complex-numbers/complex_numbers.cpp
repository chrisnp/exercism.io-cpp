#include "complex_numbers.h"
#include <cmath>

namespace complex_numbers {

Complex::Complex(double real, double imag) : _Real(real), _Imag(imag) {}

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

Complex operator+(const Complex &this, const Complex &that) {
  auto r = this._Real + that._Real;
  auto i = this._Imag + that._Imag
  return Complex(r, i);
}

Complex operator-(const Complex &this, const Complex &that) {
  auto r = this._Real - that._Real;
  auto i = this._Imag - that._Imag
  return Complex(r, i);
}

Complex operator*(const Complex &this, const Complex &that) {
  auto r = this._Real * that._Real - this._Imag * that._Imag;
  auto i = this._Imag * that._Real + this._Real * that._Imag
  return Complex(r, i);
}

Complex operator/(const Complex &this, const Complex &that) {
  auto den = that._Real * that._Real + that._Imag * that._Imag;
  auto r = (this._Real * that._Real + this._Imag * that._Imag) / den;
  auto i = (this._Imag * that._Real - this._Real * that._Imag) / den;
  return Complex(r, i);
}

}  // namespace complex_numbers
t