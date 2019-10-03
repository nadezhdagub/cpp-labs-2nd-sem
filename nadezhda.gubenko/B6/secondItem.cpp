#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>

#include "task.hpp"
#include "shape.hpp"

int detail::secondItem(std::istream &inp, std::ostream &out)
{
  inp >> std::noskipws;

  std::vector<Shape> shapes{std::istream_iterator<Shape>(inp), std::istream_iterator<Shape>()};

  if(inp.bad())
  {
    throw std::invalid_argument("Incorrect input.");
  }

  ShapesInfo infoAboutShapes = std::for_each(shapes.begin(), shapes.end(), ShapesInfo());

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
                              [] (const Shape &shape)
                              {
                                return shape.size() == 5;
                              }), shapes.end());

  std::vector<Point> points(shapes.size());

  std::transform(shapes.begin(), shapes.end(), points.begin(),
                 [](const Shape &shape)
                 {
                   return shape.at(0);
                 });

  std::sort(shapes.begin(), shapes.end());

  out << "Vertices: "   << infoAboutShapes.getVerticesCount()   << std::endl
      << "Triangles: "  << infoAboutShapes.getTrianglesCount()  << std::endl
      << "Squares: "    << infoAboutShapes.getSquaresCount()    << std::endl
      << "Rectangles: " << infoAboutShapes.getRectanglesCount() << std::endl
      << "Points: ";

  std::copy(points.begin(), points.end(), std::ostream_iterator<Point>(out, " "));
  out << std::endl << "Shapes:" << std::endl;
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape>(out, "\n"));

  return 0;
}


