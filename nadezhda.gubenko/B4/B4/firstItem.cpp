#include "tasks.hpp"
#include "notebook.hpp"
#include "factorialContainer.hpp"
#include "interfaceOfNotebook.hpp"

void firstItem()
{
  Notebook book;
  std::string string;
  while (std::getline(std::cin, string))
  {
    try
    {
      NotebookInterface phm;
      std::stringstream inp(string);
      std::string command;

      inp >> command;
      if (command == "add")
      {
        phm.addEntry(inp, book);
      }
      else if (command == "insert")
      {
        phm.insert(inp, book);
      }
      else if (command == "delete")
      {
        phm.remove(inp, book);
      }
      else if (command == "store")
      {
        phm.store(inp, book);
      }
      else if (command == "move")
      {
        phm.move(inp, book);
      }
      else if (command == "show")
      {
        try
        {
          phm.show(inp, book);
        }
        catch (std::invalid_argument &)
        {
          std::cout << "<INVALID BOOKMARK>" << std::endl;
        }
      }
      else
      {
        throw std::invalid_argument("");
      }
    }
    catch (std::invalid_argument &)
    {
      std::cout << "<INVALID COMMAND>" << std::endl;
    }
  }
}
