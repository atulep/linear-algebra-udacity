#include "vector.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

template <class T>
Vector<T>::Vector(std::initializer_list<T>coordinates) {
    for (T v : coordinates) {
      _coordinates.push_back(v);
    }
    _size = _coordinates.size();
}

template <class T>
Vector<T>::Vector(std::vector<T>coordinates) {
    for (T v : coordinates) {
      _coordinates.push_back(v);
    }
    _size = _coordinates.size();
}

template <class T>
const vector<T>& Vector<T>::getCoordinates() const {
    return _coordinates;
}

template <class T>
int Vector<T>::getSize() const {
    return _size;
}

template <class T>
double Vector<T>::len() const {
  double len = 0;
  for (auto v : _coordinates) {
    len += v*v;
  }
  return sqrt(len);
}

template <class T>
Vector<T> Vector<T>::operator+ (const Vector<T>& rhs) const {
  vector<T> v(_coordinates);    
  for (int i = 0; i < rhs.getSize(); ++i) {
    v[i] += rhs.getCoordinates()[i];
  }
  Vector r(v);
  return r;
}

template <class T>
Vector<T> Vector<T>::operator- (const Vector<T>& rhs) const {
  vector<T> v(_coordinates);
  for (int i = 0; i < rhs.getSize(); ++i) {
    v[i] -= rhs.getCoordinates()[i];
  }
  Vector r(v);
  return r;
}

template <class T>
Vector<T> Vector<T>::operator* (const double scalar) const {
  vector<T> v(_coordinates);
  for (int i = 0; i < _coordinates.size(); ++i) {
    v[i] *= scalar;
  }
  Vector r(v);
  return r;
}

template <class T>
Vector<T> Vector<T>::operator/ (const double scalar) const {
  vector<T> v(_coordinates);
  for (int i = 0; i < _coordinates.size(); ++i) {
    v[i] /= scalar;
  }
  Vector r(v);
  return r;
}

template <class T>
// dot product
double Vector<T>::operator* (const Vector<T> rhs) const {
  double ans = 0.0;
  for (int i = 0; i < rhs.getSize(); ++i) {
    ans += _coordinates[i] * rhs.getCoordinates()[i];
  }
  return ans;
}

template <class T>
double Vector<T>::angle(const Vector<T> rhs) const {
  double ans = 0.0;
  for (int i = 0; i < rhs.getSize(); ++i) {
    ans += _coordinates[i] * rhs.getCoordinates()[i];
  }
  double l1 = this->len();
  double l2 = rhs.len();
  return acos(ans / (l1 * l2)) * 180 / PI;
}

template <class T>
std::string Vector<T>::toString() const {
  std::ostringstream out;
  out << "(";
  for (int i = 0; i < _size; ++i) {
    out << std::setprecision(3) << _coordinates[i];      
    if (i < _size - 1) {
      out << ", ";
    }
  }
  out << ")";
  return out.str();
}
