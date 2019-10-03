#ifndef B4_NOTEBOOK_HPP
#define B4_NOTEBOOK_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <set>

struct NotebookEntry
{
  std::string phoneNumber, username;
};
struct EntryElement
{
  NotebookEntry entry;
  std::set<std::string> tabs;
};
class Notebook
{
public:
  Notebook();
  Notebook(const Notebook & item);
  Notebook(Notebook && item) = default;
  Notebook& operator=(const Notebook & item);
  Notebook& operator=(Notebook && item) = default;

  void addToEnd(const NotebookEntry & entry);
  void addMarkName(const std::string & current_mark, const std::string & newmark);
  void showCurrent(const std::string & mark);
  void moveToNext(const std::string & mark);
  void moveToPrev(const std::string & mark);
  void insertBefore(const std::string & mark, const NotebookEntry & entry);
  void insertAfter(const std::string & mark, const NotebookEntry & entry);
  void moveMark(const std::string & mark, int pos);
  void moveMark(const std::string & mark, const std::string & pos);
  void deleteEntry(const std::string & mark);
  void replaceEntry(const std::string & mark, const NotebookEntry & entry);

private:
  typedef std::list<EntryElement> record_type;
  typedef std::map<std::string, record_type::iterator> tab_type;
  typedef tab_type::iterator tabIter;

  record_type rec_;
  tab_type marks_;

  tabIter getIterator(const std::string & tab);
  void insert(const std::string & tab, const NotebookEntry & entry, const bool after);
};



#endif //B4_NOTEBOOK_HPP
