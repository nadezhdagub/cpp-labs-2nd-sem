#ifndef B8_SQUARE_HPP
#define B8_SQUARE_HPP

#include <iostream>

#include "shape.hpp"

class SquareC : public ShapeC
{
public:
  SquareC();
  SquareC(int x, int y);

  void draw(std::ostream & out)const override;
};


#endif //B8_SQUARE_HPP
