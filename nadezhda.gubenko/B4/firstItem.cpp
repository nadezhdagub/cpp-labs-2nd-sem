#include "tasks.hpp"
#include "notebook.hpp"
#include "factorialContainer.hpp"
#include "interfaceOfNotebook.hpp"

void detail::firstItem()
{
  detail::NoteBook noteBook;
  NotebookInterface notebookInterface(noteBook);
  std::string line = "";
  while(std::getline(std::cin, line))
  {
    try
    {
      std::stringstream in(line);
      std::string value = "";
      in >> value;
      if (value == "add")
      {
        std::string number = readNumber(in);
        std::string name = readName(in);
        notebookInterface.addEntry(detail::NoteBook::notebookEntry{number,name});
      }
      else if (value == "insert")
      {
        std::string pos = "";
        in >> pos;
        std::string mark = readMarkName(in);
        std::string number = readNumber(in);
        std::string name = readName(in);
        if(pos == "before")
        {
          notebookInterface.insertBefore(mark, detail::NoteBook::notebookEntry{number, name});
        }
        else if(pos == "after")
        {
          notebookInterface.insertAfter(mark, detail::NoteBook::notebookEntry{number, name});
        }
        else
        {
          throw std::invalid_argument("<INVALID COMMAND>");
        }
      }
      else if (value == "delete")
      {
        std::string mark = readMarkName(in);
        notebookInterface.remove(mark);
      }
      else if (value == "store")
      {
        std::string mark = readMarkName(in);
        std::string newMark = readMarkName(in);
        notebookInterface.store(mark, newMark);
      }
      else if (value == "move")
      {
        std::string mark = readMarkName(in);
        std::string step = "";
        in.ignore();
        std::getline(in, step);
        if (step == "first" || step == "last")
        {
          notebookInterface.moveMark(mark, step);
        }
        else
        {
          try
          {
            notebookInterface.moveMark(mark, stoi(step));
          }
          catch (std::invalid_argument& e)
          {
            std::cout << "<INVALID STEP>" << std::endl;
          }
        }
      }
      else if (value == "show")
      {
        std::string mark = readMarkName(in);
        notebookInterface.get(mark);
      }
      else
      {
        throw std::invalid_argument("<INVALID COMMAND>");
      }
    }
    catch (std::invalid_argument& e)
    {
      std::cout << e.what() << std::endl;
    }
  }
}

