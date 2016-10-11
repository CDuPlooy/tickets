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

	/*! Binds memento to an auditorium.
	This enables all my callbacks.
	\param auditorium: An auditorium pointer to bind to.
	*/
	void bind(Auditorium *auditorium);

	/*! Adds a command to the memento.
	\param auditorium: A std::string command to add to the memento.
	*/
	void add_command(std::string com);

	/*! Undo's an operation in the auditorium.
	*/
	void undo();

	/*! Executes a command.
	\param command: The string to execute as a command.
	*/
	void exec(std::string command);

	/*! Registers callback variables ( for updating the display in the GUI ).
	\param x: A pointer to size_t representing the x-axis.
	\param y: A pointer to size_t representing the y-axis.
	\param state: A pointer to a short representing the state of the seat.

	*/
	void callback(size_t *x , size_t *y , short *state);

	/*! Unlocks the spinlock.
	*/
	void Unlock(){
		spinLock = false;
	}

	/*! Locks the spinlock.
	*/
	void Lock(){
		spinLock = true;
	}

	/*! Determines whether the spinLock is locked or not
	\return true/false if the spinLock is enabled/disabled.
	*/
	bool isLocked(){/**< Tests if the spinlock is locketd.*/
		return spinLock;
	}
	size_t *_x , *_y;
	short *_state;
	bool guiMode;
private:
	/*! Scrapes strings from other strings.
	\param buffer: The buffer to scrape from.
	\param begin: The string representing the first identifier.
	\param end:  The string representing the end identifier.
	\returns The string scraped from buffer.
	*/
	 std::string extract(std::string buffer , std::string begin , std::string end);
	 bool spinLock;
	Auditorium *auditorium;
	std::vector<std::string> commands;

};
#endif
