#include <memory>

#include "shape.hpp"
ShapeC::ShapeC() :
  x_(0),
  y_(0)
{}

ShapeC::ShapeC(int x, int y) :
  x_(x),
  y_(y)
{}

bool ShapeC::isMoreLeft(const ShapeC *shape) const
{
  return (x_ < shape->x_);
}

bool ShapeC::isUpper(const ShapeC *shape) const
{
  return (y_ > shape->y_);
}

