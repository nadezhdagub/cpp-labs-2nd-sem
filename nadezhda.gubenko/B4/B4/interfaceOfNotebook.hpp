#ifndef B4_INTERFACEOFNOTEBOOK_HPP
#define B4_INTERFACEOFNOTEBOOK_HPP

#include "notebook.hpp"

class NotebookInterface
{
public:
  std::string readName(std::stringstream & inp);
  std::string readNumber(std::stringstream & inp);
  std::string readMarkName(std::stringstream & inp);

  void addEntry(std::stringstream & inp, Notebook & book);
  void remove(std::stringstream & inp, Notebook & book);
  void show(std::stringstream & inp, Notebook & book);
  void insert(std::stringstream & inp, Notebook & book);
  void store(std::stringstream & inp, Notebook & book);
  void move(std::stringstream & inp, Notebook & book);
};


#endif //B4_INTERFACEOFNOTEBOOK_HPP
