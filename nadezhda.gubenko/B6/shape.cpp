#include <string>
#include <iterator>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cmath>

#include "shape.hpp"

int detail::distance(const detail::Point & a, const detail::Point & b)
{
  double length = pow(a.x-b.x, 2) + pow(a.y-b.y, 2);
  return sqrt(length);
}


bool detail::operator<(const detail::Shape & first, const detail::Shape & second )
{
  if (first.size() < second.size())
  {
    return true;
  }
  if (first.size() == second.size())
  {
    if ((shapeType(first) == QUAD) && (shapeType(second) != QUAD))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

std::ostream & detail::operator<<(std::ostream & out, const detail::Point & p)
{
  return out << "(" << p.x << ";" << p.y << ")";
}

std::ostream & detail::operator<<(std::ostream & out, const detail::Shape & shape)
{
  out << shape.size();

  for (auto & point : shape)
  {
    out << " " << point;
  }

  return out << std::endl;
}

std::istream& detail::operator>> (std::istream & in, detail::Shape & shape)
{
  char ch = 0;
  size_t size = 0;
  std::string str;
  in >> size >> std::noskipws >> ch;
  if (ch == '\n')
  {
    throw std::ios_base::failure("Invalid shape");
  }
  in >> std::skipws;
  std::getline(in, str);
  if (str.empty())
  {
    return in;
  }
  std::istringstream stream(str);
  Shape tmp((std::istream_iterator<Point>(stream)), std::istream_iterator<Point>());
  shape.swap(tmp);
  shape.pop_back();
  if ((size != shape.size()) || (shape.size() < 3))
  {
    throw std::ios_base::failure("Invalid numbers of vertices");
  }
  return in;
}

std::istream & detail::operator>> (std::istream & in, detail::Point & p)
{
  std::string str;
  char ch = 0;
  std::getline(in, str, ')');
  if (str.empty() || in.eof())
  {
    return in;
  }
  std::istringstream stream(str);
  stream >> ch;
  if (ch != '(')
  {
    throw std::ios_base::failure("Invalid point1");
  }
  stream >> p.x >> ch >> p.y;
  if (ch != ';')
  {
    throw std::ios_base::failure("Invalid point2");
  }
  return in;
}

detail::ShapeType detail::shapeType(const detail::Shape & shapeIn)
{
  if (shapeIn.size() == 3)
  {
    return TRI;
  }
  else if (shapeIn.size() == 4)
  {
    double side1 = distance(shapeIn.at(0), shapeIn.at(1));
    double side2 = distance(shapeIn.at(1), shapeIn.at(2));
    double side3 = distance(shapeIn.at(2), shapeIn.at(3));
    double side4 = distance(shapeIn.at(3), shapeIn.at(0));
    if ((distance(shapeIn.at(0), shapeIn.at(2)) == distance(shapeIn.at(1), shapeIn.at(3))) &&
        (side1 == side3) && (side2 == side4))
    {
      if (side1 == side2)
      {
        return QUAD;
      }
      else
      {
        return RECT;
      }
    }
  }
  return OTHER;
}


void detail::ShapesInfo::operator()(const detail::Shape &shape)
{
  verticesCounter_ += shape.size();
  switch (shapeType(shape))
  {
    case ShapeType::TRI:
      trianglesCounter_++;
      break;
    case ShapeType::RECT:
      rectanglesCounter_++;
      break;
    case ShapeType::QUAD:
      squaresCounter_++;
      rectanglesCounter_++;
      break;
    case ShapeType::OTHER:
      break;
  }
}

size_t detail::ShapesInfo::getVerticesCount() const
{
  return verticesCounter_;
}

size_t detail::ShapesInfo::getTrianglesCount() const
{
  return trianglesCounter_;
}

size_t detail::ShapesInfo::getSquaresCount() const
{
  return squaresCounter_;
}

size_t detail::ShapesInfo::getRectanglesCount() const
{
  return rectanglesCounter_;
}

void FiguresContainer::print(std::ostream & outputStream)
{
  outputStream << "Vertices: " << std::accumulate(shapes_.begin(), shapes_.end(), 0,
                                                  [](size_t num, const Shape & shape)
                                                  {
                                                    return num += shape.size();
                                                  }) << std::endl;
  outputStream << "Triangles: " << std::count_if(shapes_.begin(), shapes_.end(),
                                                 [](const Shape & shape)
                                                 {
                                                   return defineFigureType(shape) == TRIANGLE;
                                                 }) << std::endl;
  outputStream << "Squares: "  << std::count_if(shapes_.begin(), shapes_.end(),
                                                [](const Shape & shape)
                                                {
                                                  return defineFigureType(shape) == SQUARE;
                                                }) << std::endl;
  outputStream << "Rectangles: " << std::count_if(shapes_.begin(), shapes_.end(),
                                                  [](const Shape & shape)
                                                  {
                                                    return (defineFigureType(shape) == RECTANGLE || defineFigureType(shape) == SQUARE);
                                                  }) << std::endl;

  shapes_.erase(std::remove_if(shapes_.begin(), shapes_.end(),
                               [](const Shape & shape)
                               {
                                 return shape.size() == 5;
                               }), shapes_.end());

  outputStream << "Points: ";
  std::vector<Point> points;
  std::transform(shapes_.begin(), shapes_.end(), std::back_inserter(points),
                 [](const Shape & shape)
                 {
                   return shape.at(0);
                 });
  std::for_each(points.begin(), points.end(), printPoint);

  std::sort(shapes_.begin(), shapes_.end());
  outputStream << "\nShapes: " << std::endl;
  std::for_each(shapes_.begin(), shapes_.end(), printShape);
}
