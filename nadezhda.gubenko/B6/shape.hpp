#ifndef B6_SHAPE_HPP
#define B6_SHAPE_HPP

#include <vector>
#include <iostream>

namespace detail
{
  struct Point
  {
    int x, y;
  };

  enum ShapeType
  {
    TRI,
    QUAD,
    RECT,
    OTHER
  };

  using Shape = std::vector<Point>;

  class ShapesInfo
  {
  public:
    void operator()(const Shape &);
    size_t getVerticesCount() const;
    size_t getTrianglesCount() const;
    size_t getSquaresCount() const;
    size_t getRectanglesCount() const;

  private:
    size_t verticesCounter_;
    size_t trianglesCounter_;
    size_t squaresCounter_;
    size_t rectanglesCounter_;
  };


  bool operator<(const Shape & first, const Shape & second);
  std::istream &operator>>(std::istream &, Point &point);
  std::ostream &operator<<(std::ostream &, const Point &point);
  std::istream &operator>>(std::istream &, Shape &shape);
  std::ostream &operator<<(std::ostream &, const Shape &shape);
  int distance(const Point &point1, const Point &point2);
  void print(std::ostream & outputStream);


  ShapeType shapeType(const Shape &shape);
}

#endif //B6_SHAPE_HPP
