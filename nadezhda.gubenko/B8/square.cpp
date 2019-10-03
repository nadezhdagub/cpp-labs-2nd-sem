#include "square.hpp"

SquareC::SquareC() :
  ShapeC()
{}

SquareC::SquareC(int x, int y) :
  ShapeC(x, y)
{}

void::SquareC::draw(std::ostream & out)const
{
  out << "SQUARE " << "(" << x_ << "; " << y_ << ")" << std::endl;
}


