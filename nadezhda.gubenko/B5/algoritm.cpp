#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <vector>

#include "algoritm.hpp"

const int maxKey1AndKey2 = 5;
const int minKey1AndKey2 = -5;

bool detail::operator<(const DataStruct & data1, const DataStruct & data2)
{
  if (data1.key1 < data2.key1)
  {
    return true;
  }
  else if (data1.key1 == data2.key1)
  {
    if (data1.key2 < data2.key2)
    {
      return true;
    }
    else if (data1.key2 == data2.key2)
    {
      if (data1.str.size() < data2.str.size())
      {
        return true;
      }
    }
  }

  return false;
}

void missComma(std::istream & inp)
{
  char temp;
  if (!(inp >> temp).good() || temp != ',')
  {
    throw std::invalid_argument("Invalid delimetre");
  }
}

size_t detail::keyRead(std::stringstream & inp)
{
  int key = 0;
  inp >> key;

  if ((key < minKey1AndKey2) || (key > maxKey1AndKey2))
  {
    throw std::invalid_argument("Wrong key!");
  }
  if (inp.fail())
  {
    throw std::istream::failure("Wrong input");
  }
  return key;
}

std::istream & detail::operator >>(std::istream & inp, detail::DataStruct & data)
{
  std::string str;
  getline(inp, str);
  if (!inp.good())
  {
    return inp;
  }

  std::stringstream tmpStream(str);
  data.key1 = detail::keyRead(tmpStream);
  missComma(tmpStream);
  data.key2 = detail::keyRead(tmpStream);
  missComma(tmpStream);
  getline(tmpStream, str);
  data.str = str;
  if (str.empty())
  {
    throw std::invalid_argument("Empty string");
  }
  if (inp.fail())
  {
    throw std::istream::failure("Wrong input parametres");
  }
  return inp;
}

std::ostream& detail::operator <<(std::ostream & out, const detail::DataStruct & data)
{
  out << data.key1 << "," << data.key2 << "," << data.str;
  return out;
}

void task()
{
  std::vector<detail::DataStruct> dataVect;
  std::copy(std::istream_iterator<detail::DataStruct>(std::cin), std::istream_iterator<detail::DataStruct>(), std::back_inserter(dataVect));
  if (!std::cin.eof())
  {
    throw std::istream::failure("Problems with input");
  }
  std::sort(dataVect.begin(), dataVect.end());
  std::copy(dataVect.begin(), dataVect.end(), std::ostream_iterator<detail::DataStruct>(std::cout, "\n"));
}
