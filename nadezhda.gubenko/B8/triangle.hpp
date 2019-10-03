#ifndef B8_TRIANGLE_HPP
#define B8_TRIANGLE_HPP

#include <iostream>

#include "shape.hpp"

class TriangleC : public ShapeC
{
public:
  TriangleC();
  TriangleC(int x, int y);

  void draw(std::ostream & out) const override;
};


#endif //B8_TRIANGLE_HPP
