#include "Vec3.h"

Vec3::Vec3(float x, float y)
{
  this->x = x;
  this->y = y;
}

float Vec3::dot(Vec3 a)
{
  return a.x*this->x + a.y*this->y;
}