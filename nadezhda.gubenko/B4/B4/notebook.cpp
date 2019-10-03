#include "notebook.hpp"

Notebook::Notebook()
{
  marks_["current"] = rec_.end();
}

Notebook::Notebook(const Notebook & other)
{
  *this = other;
}

Notebook & Notebook::operator=(const Notebook & other)
{
  if (this != &other)
  {
    rec_ = other.rec_;
    marks_.clear();
    for (auto i = other.marks_.cbegin(); i != other.marks_.cend(); i++)
    {
      std::list<EntryElement>::const_iterator tabs = i->second;
      marks_[i->first] = std::next(rec_.begin(), std::distance(other.rec_.cbegin(), tabs));
    }
  }
  return *this;
}

void Notebook::replaceEntry(const std::string & tab, const NotebookEntry & entry)
{
  auto iter = getIterator(tab);
  iter->second->entry = entry;
}

void Notebook::showCurrent(const std::string & tab)
{
  auto iter = getIterator(tab);
  if (iter->second == rec_.end())
  {
    std::cout << "<EMPTY>" << std::endl;
  }
  else
  {
    std::cout << iter->second->entry.phoneNumber << " " << iter->second->entry.username << std::endl;
  }
}

void Notebook::addToEnd(const NotebookEntry & entry)
{
  EntryElement newElem;
  newElem.entry = entry;
  if (rec_.empty())
  {
    newElem.tabs.insert("current");
    rec_.push_back(newElem);
    marks_["current"] = rec_.begin();
  }
  else
  {
    rec_.push_back(newElem);
  }
}

void Notebook::addMarkName(const std::string & current_mark, const std::string & new_mark)
{
  auto iter = getIterator(current_mark);
  marks_[new_mark] = iter->second;
  if (iter->second != rec_.end())
  {
    iter->second->tabs.insert(new_mark);
  }
}

void Notebook::insertBefore(const std::string & tab, const NotebookEntry & entry)
{
  insert(tab, entry, false);
}

void Notebook::insertAfter(const std::string & tab, const NotebookEntry & entry)
{
  insert(tab, entry, true);
}

void Notebook::insert(const std::string & tab, const NotebookEntry & entry, const bool after)
{
  if (rec_.empty())
  {
    addToEnd(entry);
    return;
  }
  auto iter = getIterator(tab);
  if (iter->second != rec_.end())
  {
    if (!after)
    {
      rec_.insert(iter->second, EntryElement{ entry, });
    }
    else
    {
      rec_.insert(std::next(iter->second), EntryElement{ entry, });
    }
  }
  else
  {
    rec_.push_back(EntryElement{ entry, });
  }
}

void Notebook::deleteEntry(const std::string & tab)
{
  auto iter = getIterator(tab);
  if (iter->second != rec_.end())
  {
    auto elem = iter->second;
    for (auto i : elem->tabs)
    {
      if ((std::next(elem) == rec_.end()) && (rec_.size() > 1))
      {
        marks_.at(i) = std::prev(elem);
        std::prev(elem)->tabs.insert(i);
      }
      else
      {
        marks_.at(i) = std::next(elem);
        if (std::next(elem) != rec_.end())
        {
          std::next(elem)->tabs.insert(i);
        }
      }
    }
    rec_.erase(elem);
  }
}

void Notebook::moveToPrev(const std::string & mark)
{
  moveMark(mark, -1);
}

void Notebook::moveToNext(const std::string & mark)
{
  moveMark(mark, 1);
}

Notebook::tabIter Notebook::getIterator(const std::string & mark)
{
  auto iter = marks_.find(mark);
  if (iter == marks_.end())
  {
    throw std::invalid_argument("error");
  }
  return iter;
}

void Notebook::moveMark(const std::string & mark, int pos)
{
  auto iter = getIterator(mark);
  if (iter->second != rec_.end())
  {
    iter->second->tabs.erase(mark);
  }
  std::advance(iter->second, pos);

  if (iter->second != rec_.end())
  {
    iter->second->tabs.insert(mark);
  }
}

void Notebook::moveMark(const std::string & mark, const std::string & pos)
{
  auto iter = getIterator(mark);
  if (pos != "first" && pos != "last")
  {
    std::cout << "<INVALID STEP>" << std::endl;
  }
  else
  {
    if (iter->second != rec_.end())
    {
      iter->second->tabs.erase(mark);
    }
    if (rec_.empty())
    {
      iter->second = rec_.end();
    }
    else
    {
      if (pos == "first")
      {
        iter->second = rec_.begin();
      }
      else
      {
        iter->second = std::prev(rec_.end());
      }
      iter->second->tabs.insert(mark);
    }
  }
}
