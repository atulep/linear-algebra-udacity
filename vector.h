#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <string>

#define PI 3.14159265

using std::vector;

template <class T>
class Vector {
private:
  vector<T>_coordinates;
  int _size;
public:
  Vector(std::initializer_list<T>coordinates);
  Vector(std::vector<T>coordinates);
  // reference to const
  const vector<T>& getCoordinates() const;
  int getSize() const;
  double len() const;
  Vector<T> operator+ (const Vector<T>& rhs) const;
  Vector<T> operator- (const Vector<T>& rhs) const;
  Vector<T> operator* (const double scalar) const;
  Vector<T> operator/ (const double scalar) const;
  // dot product
  double operator* (const Vector<T> rhs) const;
  // degrees
  double angle(const Vector<T> rhs) const;
  std::string toString() const;
};

#endif
