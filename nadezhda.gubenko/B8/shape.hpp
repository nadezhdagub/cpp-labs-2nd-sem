#ifndef B8_SHAPE_HPP
#define B8_SHAPE_HPP

#include <memory>

class ShapeC
{
public:
  ShapeC();
  ShapeC(int x, int y);
  virtual ~ShapeC() = default;

  bool isMoreLeft(const ShapeC *shape) const;
  bool isUpper(const ShapeC *shape) const;
  virtual void draw(std::ostream & out) const = 0;

protected:
  int x_;
  int y_;
};


#endif //B8_SHAPE_HPP
