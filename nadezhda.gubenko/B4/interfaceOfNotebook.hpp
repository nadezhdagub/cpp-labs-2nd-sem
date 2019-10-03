#ifndef B4_INTERFACEOFNOTEBOOK_HPP
#define B4_INTERFACEOFNOTEBOOK_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "notebook.hpp"

class NotebookInterface
{
public:
  NotebookInterface(detail::NoteBook & noteBook);

  typedef std::map<std::string, detail::NoteBook::noteBookIter>::iterator iterMark;

  void addEntry(const detail::NoteBook::notebookEntry & book);
  void remove(const std::string & book);
  void store(const std::string & mark, const std::string & newMarkName);
  void moveToNext(const std::string & mark);
  void moveToPrev(const std::string & mark);
  void moveMark(const std::string & mark, const std::string & step);
  void moveMark(const std::string & mark, const int & step);
  void insertBefore(const std::string & mark, const detail::NoteBook::notebookEntry & book);
  void insertAfter(const std::string & mark, const detail::NoteBook::notebookEntry & book);
  void get(const std::string & mark);

private:
  detail::NoteBook & notebook_;
  std::map<std::string, detail::NoteBook::noteBookIter> bookmarks_;

  bool isMark(const std::string & mark);
  iterMark getIter(const std::string & mark);
};

std::string readNumber(std::istream & in);
std::string readName(std::istream & in);
std::string readMarkName(std::istream & in);



#endif //B4_INTERFACEOFNOTEBOOK_HPP
