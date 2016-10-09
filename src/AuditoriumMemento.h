/**
 * \class AuditoriumMemento

 * \brief Aggregate of auditorium and it's subclasses , can undo any operation performed on auditorium.

 */
#ifndef AUDITORIUMMEMENTO_H
#define AUDITORIUMMEMENTO_H
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
	void callback(size_t *x , size_t *y , short *state); /**< Sets the callback variables for the memento.*/
	void Unlock(){ /**< Unlocks the spinlock.*/
		spinLock = false;
	}
	void Lock(){ /**< Locks the spinlock.*/
		spinLock = true;
	}
	bool isLocked(){/**< Tests if the spinlock is locketd.*/
		return spinLock;
	}
	size_t *_x , *_y;
	short *_state;
	bool guiMode;
private:
	 std::string extract(std::string buffer , std::string begin , std::string end);/**< Extracts a substring.*/
	 bool spinLock;
	Auditorium *auditorium;
	std::vector<std::string> commands;


};
#endif
