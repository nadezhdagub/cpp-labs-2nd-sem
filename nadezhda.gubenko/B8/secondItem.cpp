#include <algorithm>
#include <iterator>
#include <memory>
#include <sstream>
#include <vector>
#include <functional>

#include "triangle.hpp"
#include "square.hpp"
#include "circle.hpp"
#include "shape.hpp"
#include "task.hpp"

using shape_ptr = std::unique_ptr<ShapeC>;

std::vector<shape_ptr> readShapes(std::istream &inp)
{
  std::vector<shape_ptr> vector;
  std::string name;
  while(!(inp >> std::ws).eof()) {
    char open_bracket = '\0', close_bracket = '\0', delimiter = '\0';
    int x = 0, y = 0;
    std::getline(inp, name);
    auto openBracketPos = name.find('(');
    if(openBracketPos == name.npos)
    {
      throw std::invalid_argument("Incorrect data.");
    }
    else
    {
      name.insert(openBracketPos, " ");
    }

    std::istringstream currentLine(name);
    currentLine.exceptions(std::istringstream::failbit | std::istringstream::badbit);
    currentLine >> std::skipws >> name >> open_bracket >> x >> delimiter >> y >> close_bracket;
    if(open_bracket != '(' || delimiter != ';' || close_bracket != ')' || !(currentLine >> std::ws).eof())
    {
      throw std::invalid_argument("Incorrect data.");
    }

    if (name == "TRIANGLE")
    {
      vector.emplace_back(std::make_unique<TriangleC>(TriangleC(x, y)));
    }
    else if(name == "SQUARE")
    {
      vector.emplace_back(std::make_unique<SquareC>(SquareC(x, y)));
    }
    else if(name == "CIRCLE")
    {
      vector.emplace_back(std::make_unique<CircleC>(CircleC(x, y)));
    }
    else
    {
      throw std::invalid_argument("Incorrect data.");
    }
  }
  return vector;
}

void secondItem(std::istream &inp, std::ostream &out)
{
  std::vector<shape_ptr> vector = readShapes(inp);
  out << "Original:" << std::endl;
  std::for_each(vector.begin(), vector.end(), std::bind(&ShapeC::draw, std::placeholders::_1, std::ref(out)));

  out << "Left-Right:" << std::endl;
  std::sort(vector.begin(), vector.end(),std::bind(&ShapeC::isMoreLeft,
                                                   std::bind(&std::unique_ptr<ShapeC>::get, std::placeholders::_1),
                                                   std::bind(&std::unique_ptr<ShapeC>::get, std::placeholders::_2)));

  std::for_each(vector.begin(), vector.end(), std::bind(&ShapeC::draw, std::placeholders::_1, std::ref(out)));

  out << "Right-Left:" << std::endl;
  std::sort(vector.begin(), vector.end(),std::bind(&ShapeC::isMoreLeft,
                                                   std::bind(&std::unique_ptr<ShapeC>::get, std::placeholders::_2),
                                                   std::bind(&std::unique_ptr<ShapeC>::get, std::placeholders::_1)));

  std::for_each(vector.begin(), vector.end(), std::bind(&ShapeC::draw, std::placeholders::_1, std::ref(out)));


  out << "Top-Bottom:" << std::endl;
  std::sort(vector.begin(), vector.end(), std::bind(&ShapeC::isUpper,
                                                    std::bind(&std::unique_ptr<ShapeC>::get, std::placeholders::_1),
                                                    std::bind(&std::unique_ptr<ShapeC>::get, std::placeholders::_2)));

  std::for_each(vector.begin(), vector.end(), std::bind(&ShapeC::draw, std::placeholders::_1, std::ref(out)));

  out << "Bottom-Top:" << std::endl;
  std::sort(vector.begin(), vector.end(), std::bind(&ShapeC::isUpper,
                                                    std::bind(&std::unique_ptr<ShapeC>::get, std::placeholders::_2),
                                                    std::bind(&std::unique_ptr<ShapeC>::get, std::placeholders::_1)));

  std::for_each(vector.begin(), vector.end(), std::bind(&ShapeC::draw, std::placeholders::_1, std::ref(out)));
}
