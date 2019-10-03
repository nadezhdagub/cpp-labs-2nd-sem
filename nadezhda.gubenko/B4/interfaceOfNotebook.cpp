#include <algorithm>

#include "interfaceOfNotebook.hpp"

NotebookInterface::NotebookInterface(detail::NoteBook & phoneBook):
  notebook_(phoneBook)
{
  bookmarks_["current"] = notebook_.getBegin();
}

std::string readNumber(std::istream & in)
{
  std::string number = "";
  in >> number;
  for(char symbol: number)
  {
    if(!std::isdigit(symbol))
    {
      throw std::invalid_argument("<INVALID COMMAND>");
    }
  }
  return number;
}

std::string readName(std::istream & in)
{
  in.ignore();
  std::string name = "";
  std::getline(in,name);
  if(name.front() != '\"' || name.back() != '\"')
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }
  name.erase(0,1);
  name.pop_back();
  name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());
  return name;
}

std::string readMarkName(std::istream & in)
{
  std::string mark = "";
  in >> mark;
  for(char symbol: mark)
  {
    if(!std::isalnum(symbol) && symbol != '-')
    {
      throw std::invalid_argument("<INVALID COMMAND>");
    }
  }
  return mark;
}

void NotebookInterface::addEntry(const detail::NoteBook::notebookEntry & note)
{
  notebook_.addToEnd(note);
  if (notebook_.getEntry() == 1)
  {
    bookmarks_["current"] = notebook_.getBegin();
  }
}

void NotebookInterface::remove(const std::string & mark)
{
  if (!isMark(mark))
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
    return;
  }
  detail::NoteBook::noteBookIter deletedElement = bookmarks_[mark];
  for (iterMark it = bookmarks_.begin(); it != bookmarks_.end(); it++)
  {
    if (it->second != std::prev(notebook_.getEnd()))
    {
      detail::NoteBook::noteBookIter tmpIter = std::next(it->second);
      it->second = tmpIter;
    }
    else
    {
      detail::NoteBook::noteBookIter tmpIter = std::prev(it->second);
      it->second = tmpIter;
    }
  }
  notebook_.deleteEntry(deletedElement);
}

void NotebookInterface::store(const std::string & mark, const std::string & newMarkName)
{
  if (isMark(mark))
  {
    bookmarks_[newMarkName] = bookmarks_[mark];
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
  }
}

void NotebookInterface::moveToNext(const std::string & mark)
{
  moveMark(mark, 1);
}
void NotebookInterface::moveToPrev(const std::string & mark)
{
  moveMark(mark, -1);
}

void NotebookInterface::moveMark(const std::string & mark, const int & step)
{
  if ((step < 0 && std::distance(notebook_.getBegin(), bookmarks_[mark]) < (-1*step)) ||
      (step > 0 && std::distance(bookmarks_[mark], notebook_.getEnd()) < step))
  {
    throw std::out_of_range("Out of the phoneBook!");
  }
  iterMark iterator = getIter(mark);
  std::advance(iterator -> second, step);
}

void NotebookInterface::moveMark(const std::string & mark, const std::string & step)
{
  iterMark iterator = getIter(mark);
  if(!notebook_.isEmpty())
  {
    if(step == "first")
    {
      iterator -> second = notebook_.getBegin();
    }
    else
    {
      iterator -> second = std::prev(notebook_.getEnd());
    }
  }
}

void NotebookInterface::insertBefore(const std::string & mark, const detail::NoteBook::notebookEntry & note)
{
  if (isMark(mark))
  {
    notebook_.insert(true, bookmarks_[mark], note);
    detail::NoteBook::noteBookIter it = bookmarks_[mark];
    bookmarks_[mark] = std::prev(it);
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
  }
}

void NotebookInterface::insertAfter(const std::string & mark, const detail::NoteBook::notebookEntry & note)
{
  if (isMark(mark))
  {
    notebook_.insert(false, bookmarks_[mark], note);
    detail::NoteBook::noteBookIter it = bookmarks_[mark];
    bookmarks_[mark] = std::next(it);
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
  }
}
void NotebookInterface::get(const std::string & mark)
{
  if (isMark(mark))
  {
    notebook_.showCurrent(bookmarks_[mark]);
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>" << std::endl;
  }
}

NotebookInterface::iterMark NotebookInterface::getIter(const std::string & mark)
{
  iterMark iterator = bookmarks_.find(mark);
  if (iterator == bookmarks_.end())
  {
    throw std::invalid_argument("<INVALID BOOKMARK>");
  }
  return iterator;
}



bool NotebookInterface::isMark(const std::string & mark)
{
  return (!(bookmarks_.find(mark) == bookmarks_.end()));
}


