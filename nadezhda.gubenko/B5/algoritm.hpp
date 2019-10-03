#ifndef B5_ALGORITM_HPP
#define B5_ALGORITM_HPP

#include <sstream>

#include "DataStruct.hpp"

namespace detail
{

  bool operator<(const DataStruct &data1, const DataStruct &data2);
  std::istream &operator>>(std::istream &inp, DataStruct &data);
  std::ostream &operator<<(std::ostream &out, const DataStruct &data);
  size_t keyRead(std::stringstream &inp);
}

void task();

#endif //B5_ALGORITM_HPP
