/**
The MIT License (MIT)

Copyright (c) 2015 Ginger Bill
Copyright (c) 2016 Flavio Moreira

Original License:
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files ("Dunjun"), to deal in Dunjun without restriction, including without
limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of Dunjun, and to permit persons to whom Dunjun is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of Dunjun.

Dunjun is provided "as is", without warranty of any kind, express or implied, including but not
limited to the warranties of merchantability, fitness for a particular purpose and noninfringement.
In no event shall the authors or copyright holders be liable for any claim, damages or other
liability, whether in an action of contract, tort or otherwise, arising from, out of or in
connection with Dunjun or the use or other dealings in Dunjun.

* Original file from Dunjun: https://github.com/gingerBill/Dunjun

NOTE: This file was modified to fit the Broome project
*/

#include "vector2.hpp"
#include "functions.hpp"

namespace Broome
{

const Vector2 Vector2::Zero = {0, 0};

bool operator==(const Vector2& a, const Vector2& b)
{
  for(usize i = 0; i < 2; i++)
  {
    if(a[i] != b[i])
      return false;
  }

  return true;
}

bool operator!=(const Vector2& a, const Vector2& b) { return !operator==(a, b); }

Vector2 operator-(const Vector2& a) { return {-a.x, -a.y}; }

Vector2 operator+(const Vector2& a, const Vector2& b) { return {a.x + b.x, a.y + b.y}; }

Vector2 operator-(const Vector2& a, const Vector2& b) { return {a.x - b.x, a.y - b.y}; }

Vector2 operator*(const Vector2& a, Scalar scalar) { return {scalar * a.x, scalar * a.y}; }

Vector2 operator/(const Vector2& a, Scalar scalar) { return {a.x / scalar, a.y / scalar}; }

// Hadamard Product
Vector2 operator*(const Vector2& a, const Vector2& b)
{
  Vector2 result;
  for(usize i = 0; i < 2; i++)
    result[i] = a[i] * b[i];
  return result;
}

// Hadamard Product
Vector2 operator/(const Vector2& a, const Vector2& b)
{
  Vector2 result;
  for(usize i = 0; i < 2; i++)
    result[i] = a[i] / b[i];
  return result;
}

Vector2& operator+=(Vector2& a, const Vector2& b)
{
  a.x += b.x;
  a.y += b.y;

  return a;
}

Vector2& operator-=(Vector2& a, const Vector2& b)
{
  a.x -= b.x;
  a.y -= b.y;

  return a;
}

Vector2& operator*=(Vector2& a, Scalar scalar)
{
  a.x *= scalar;
  a.y *= scalar;

  return a;
}

Vector2& operator/=(Vector2& a, Scalar scalar)
{
  a.x /= scalar;
  a.y /= scalar;

  return a;
}

Scalar dot(const Vector2& a, const Vector2& b) { return a.x * b.x + a.y * b.y; }

Scalar cross(const Vector2& a, const Vector2& b) { return a.x * b.y - b.x * a.y; }

Scalar lengthSq(const Vector2& a) { return dot(a, a); }

Scalar length(const Vector2& a) { return std::sqrt(lengthSq(a)); }

Vector2 normalize(const Vector2& a) { return a * (1.0f / length(a)); }

} // namespace Broome
