#include <iostream>

#include "interfaceOfNotebook.hpp"

std::string NotebookInterface::readName(std::stringstream & inp)
{
  inp.ignore();
  std::string name;
  std::getline(inp, name);

  if (name.empty())
  {
    return name;
  }

  if ((name.front() != '\"') || (name.back() != '\"'))
  {
    throw std::invalid_argument("incorrect name");
  }
  name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());
  name.erase(0, 1);
  name.pop_back();
  return name;
}

std::string NotebookInterface::readNumber(std::stringstream & inp)
{
  std::string number;
  inp >> number;
  for (auto i : number)
  {
    if (!isdigit(i))
    {
      throw std::invalid_argument("<INVALID COMMAND>");
    }
  }
  return number;
}

void NotebookInterface::show(std::stringstream & inp, Notebook & book)
{
  std::string markName = readMarkName(inp);
  book.showCurrent(markName);
}

void NotebookInterface::insert(std::stringstream & inp, Notebook & book)
{
  std::string pos;
  inp >> pos;

  if ((pos != "before") && (pos != "after"))
  {
    throw std::invalid_argument("Wrong parameter");
  }
  else
  {
    std::string markName = readMarkName(inp);
    std::string number = readNumber(inp);
    std::string name = readName(inp);

    if (pos == "after")
    {
      book.insertAfter(markName, NotebookEntry{ number, name });
    }
    else
    {
      book.insertBefore(markName, NotebookEntry{ number,name });
    }
  }
}

void NotebookInterface::addEntry(std::stringstream & inp, Notebook & book)
{
  std::string number = readNumber(inp);
  std::string name = readName(inp);
  book.addToEnd(NotebookEntry{ number,name });
}

void NotebookInterface::move(std::stringstream& inp, Notebook & book)
{
  std::string markName = readMarkName(inp);
  std::string pos;
  inp >> pos;

  if (pos != "first" && pos != "last")
  {
    try
    {
      book.moveMark(markName, std::stoi(pos));
    }
    catch (std::invalid_argument &)
    {
      std::cout << "<INVALID STEP>" << std::endl;
    }
  }
  else
  {
    book.moveMark(markName, pos);
  }
}

void NotebookInterface::remove(std::stringstream & inp, Notebook & book)
{
  std::string markName = readMarkName(inp);
  book.deleteEntry(markName);
}

std::string NotebookInterface::readMarkName(std::stringstream & inp)
{
  std::string markName;
  inp >> markName;
  for (auto i : markName)
  {
    if ((!isalnum(i)) && (i != '-'))
    {
      throw std::invalid_argument("<INVALID BOOKMARK>");
    }
  }
  return markName;
}

void NotebookInterface::store(std::stringstream& inp, Notebook & book)
{
  std::string oldMark = readMarkName(inp);
  std::string newMark = readMarkName(inp);
  book.addMarkName(oldMark, newMark);
}

