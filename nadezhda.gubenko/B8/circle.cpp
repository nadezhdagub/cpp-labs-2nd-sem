#include "circle.hpp"

#include <iostream>

CircleC::CircleC() :
  ShapeC()
{}

CircleC::CircleC(int x, int y) :
  ShapeC(x, y)
{}

void::CircleC::draw(std::ostream & out) const
{
  out << "CIRCLE " << "(" << x_ << "; " << y_ << ")" << std::endl;
}
