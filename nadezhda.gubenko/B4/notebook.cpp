#include <iostream>
#include "notebook.hpp"

void detail::NoteBook::addToEnd(const notebookEntry & note)
{
  notebook_.push_back(note);
}

void detail::NoteBook::insert(const bool isBefore, const noteBookIter iter, const NoteBook::notebookEntry & note)
{
  if(isEmpty())
  {
    addToEnd(note);
  }
  else
  {
    if(isBefore)
    {
      notebook_.insert(iter, note);
    }
    else
    {
      notebook_.insert(std::next(iter), note);
    }
  }
}

void detail::NoteBook::deleteEntry(const noteBookIter & iter)
{
  notebook_.erase(iter);
}

void detail::NoteBook::showCurrent(const noteBookIter & iter)
{
  if (isEmpty())
  {
    throw std::invalid_argument("<EMPTY>");
  }
  std::cout << iter -> first << " " << iter -> second << std::endl;
}

size_t detail::NoteBook::getEntry()
{
  return notebook_.size();
}

detail::NoteBook::noteBookIter detail::NoteBook::getBegin()
{
  return  notebook_.begin();
}

detail::NoteBook::noteBookIter detail::NoteBook::getEnd()
{
  return  notebook_.end();
}

bool detail::NoteBook::isEmpty()
{
  return notebook_.empty();
}

