#include <iterator>
#include <iostream>
#include <algorithm>
#include <cmath>

#include "task.hpp"

void firstItem(std::istream &inp, std::ostream &out)
{
  std::transform(std::istream_iterator<double>(inp), std::istream_iterator<double>(),
                 std::ostream_iterator<double>(out, " "), std::bind2nd(std::multiplies<double>(), M_PI));

  if(!inp.eof())
  {
    throw std::invalid_argument("Incorrect data.");
  }
}

