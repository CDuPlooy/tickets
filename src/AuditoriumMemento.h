#ifndef AUDITORIUM_MEMENTO_H
#define AUDITORIUM_MEMENTO_H
#include <vector>
#include "Object.h"
class Auditorium;	// Makes an empty promise to the compiler.
class AuditoriumMemento : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~AuditoriumMemento();
      AuditoriumMemento();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
	void bind(Auditorium *auditorium); /**< When a memento is constructed it will be bound to an auditorium and the auditorium bound to it.*/
	void add_command(std::string); /**< Adds a command to the list.*/
	void undo(); /**< Removes the command at the top of the list and executes it.*/
	void exec(std::string command);/**< Executes a command.*/
private:
	Auditorium *auditorium;
	std::vector<std::string> commands;
};
#endif
