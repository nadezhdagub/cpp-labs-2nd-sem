#ifndef B8_CIRCLE_HPP
#define B8_CIRCLE_HPP

#include "shape.hpp"

class CircleC : public ShapeC
{
public:
  CircleC();
  CircleC(int x, int y);

  void draw(std::ostream & out)const override;
};


#endif //B8_CIRCLE_HPP
