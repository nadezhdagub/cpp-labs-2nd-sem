#ifndef B4_NOTEBOOK_HPP
#define B4_NOTEBOOK_HPP

#include <string>
#include <list>
#include <map>

namespace detail
{
  class NoteBook
  {
  public:
    typedef std::pair<std::string, std::string> notebookEntry;
    typedef std::list<notebookEntry>::iterator noteBookIter;

    NoteBook() = default;

    void addToEnd(const notebookEntry &entry);
    void showCurrent(const noteBookIter &iter);
    void insert(const bool isBefore, const noteBookIter iter, const notebookEntry & note);
    void deleteEntry(const noteBookIter &iter);
    noteBookIter getBegin();
    noteBookIter getEnd();
    size_t getEntry();
    bool isEmpty();

  private:
    std::list<notebookEntry> notebook_;
  };
}



#endif //B4_NOTEBOOK_HPP
