#include "triangle.hpp"

TriangleC::TriangleC() :
  ShapeC()
{}
TriangleC::TriangleC(int x, int y) :
  ShapeC(x, y)
{}
void::TriangleC::draw(std::ostream & out)const
{
  out << "TRIANGLE " << "(" << x_ << "; " << y_ << ")" << std::endl;
}
