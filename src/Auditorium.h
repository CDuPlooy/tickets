//!  An abstract class.
/*!
  An abstract class which provides an interface to the different types of auditoriums.
*/
#ifndef AUDITORIUM_H
#define AUDITORIUM_H
#include "Object.h"
#include "Seat.h"
#include "Group.h"
#include "Person.h"
#include "TicketPrinter.h"
#include "AuditoriumMemento.h"
#include "Booking.h"
#include <ctime>
#include <pthread.h>
//Class
/*! Trampoline function for pthread_create.
*/
class Auditorium;


class Auditorium : public Object{
protected:
      int compareTo(Object const &) const;  /**< Compares two instances of Object.x*/
public:
      //Constructors
      ~Auditorium(); /**< Constructs the Auditorium class.*/
      Auditorium();  /**< Destroys the Auditorium class.*/
      //Overloaded Functions

      bool isNull(void) const;
      int compare(Object const &) const; /**< Used to compare different Auditoriums. */
      void print(std::ostream & = std::cout) const; /**< Generates output for a stream , using std::cout as the default. */
      std::string getId() const;    /**< Returns a string representing the ID/Type of an object. */

      //Unique Functions
	/*! Gets the name associated with the class.
    \return Returns the  name of the auditorium.
	*/
      std::string getName(){
          return name;
      }
	/*! Sets the name associated with the class.
    \param name: A name as a string.
	*/
      void setName(std::string name){
          this->name = name;
      }
      //Pure Virtual Functions
	/*! Books an auditorium seat.
	\param person: A pointer to a person.
	\param row: A size_t representing the row.
 	\param column: A size_t representing the column.
	\return true/false representing whether the booking failed or not.
	*/
      virtual bool book(Person *person , size_t row, size_t column) = 0;

	/*! Cancels a booking of an auditorium seat.
	\param row: A size_t representing the row.
	\param column: A size_t representing the column.
	*/
	virtual void cancelBooking(size_t row, size_t column) = 0;

	/*! Finds a free auditorium seat.
	\param row: A size_t reference representing the row.
	\param column: A size_t referencere presenting the column.
	*/
      virtual bool findFree(size_t &row, size_t &column) = 0;

	/*! Checks the boundry inside the class.
	\param row: A size_t  representing the row.
	\param column: A size_t  presenting the column.
	\return true/false whether the index is valid (not NULL).
	*/
      virtual bool checkBoundry( size_t row, size_t column) = 0;

	/*! Sets a part of the auditorium to void.
	\param row: A size_t reference representing the row.
	\param column: A size_t referencere presenting the column.
	\param vertical: A boolean value to set either horizontally or vertically.
	\return true/false whether the spaces were set to void.
	*/
      virtual bool setVoid(size_t row, size_t column, size_t n, bool vertical) = 0;

	/*! Advanced bookings ( for groups ).
	\param Group: A reference to a Group object which holds a variable number of People.
	\return true/false whether the spaces were set to void.
	*/
      virtual bool bookAdv(Group &group ) = 0;

	/*! Sets the state of a given seat by delegation.
	\param row: A size_t  representing the row.
	\param column: A size_t  presenting the column.
	\param value: A short representing the type of seat.
	\return true/false whether free spaces for the group were found.
	*/
      virtual void setState( size_t row, size_t column, short value ) = 0;

	/*! Gets the state of a given seat by delegation.
	\param row: A size_t  representing the row.
	\param column: A size_t  presenting the column.
	\return A short representing state.
	*/
      virtual short getState( size_t row, size_t column) = 0;

	/*! Gets the seat at a given position.
	\param row: A size_t  representing the row.
	\param column: A size_t  presenting the column.
	\return A seat pointer.
	*/
      virtual Seat *getSeat( size_t row, size_t column) = 0;

	/*! Gets a string representation of an auditorium.
	\return A raw string without terminal colour codes..
	*/
      virtual std::string dumpRaw() = 0;

	/*! Gets a string representation of an auditorium.
	\param filename: The name of the file to dump the data to.
	*/
      virtual void dumpFile(std::string filename) = 0;

	//Part of the memento implementation.

	/*! Enables memento via delegation.
	\param value: A boolean to either enable/disable memento.
	*/
	void enableMemento(bool value);

	/*!Determines whether the internal memento pointer is linked to an auditorium.
	\return true/false whether a memento is linked.
	*/
	bool mementoLinked();

	/*! Creates a new memento.
	*/
	void createMemento();

	/*! Destroys the current memento.
	*/
	void deleteMemento();

	/*! Gets the internal memento.
	\return A AuditoriumMemento instance.
	*/
	AuditoriumMemento *getMemento();

	/*! Adds a command to the memento.
	\param com: The command to add
	*/
	void add_command(std::string com);

	/*! Invokes the memento undo function by deleting the command from the top of the STL vector.
	*/
	void undo();

	/*! Returns whether internally a TicketPrinter is linked.
	\return true/false if Printer is linked..
	*/
	bool ticketPrinterLinked();

	/*! Used to enable/disable TicketPrinter..
	\param true/false to enable/disable the Printer.
	*/
	void enablePrinter(bool val);

	/*! Prints a ticket for the particular seat.
	\param seat: A seat pointer.
	\param printRaw: Determines whether to print terminal colour codes.
	*/
	void printSeat(Seat *seat , bool printRaw){
		if(ticketPrinterLinked() && !guiMode){
			std::cout << "Auditorium:" << getName() << std::endl;
			printer->printSeat(seat, false);
		}
	}
	bool guiMode;

	/*! Creates a copy of the current auditorium.
	\return A new auditorium pointer.
	*/
	virtual Auditorium *clone() = 0;

	/*! Determines whether the mutex is locked.
	\return true/false for locked/unlocked.
	*/
	bool isLocked(){
		return _mutex;
	}

	/*! Loops until the mutex can be locked
	*/
	void tryLock(){
		while( _mutex == true ){}
		_mutex = true;
	}

	/*! Unlocks the mutex.
	*/
	void unlock(){
		_mutex = false;
	}

	/*! Clears the auditorium in n seconds.
	\param seconds: The amount of seconds to wait.
	\return true/false whether the thread was spawned.
	*/
	bool clearIn(size_t seconds){
		pthread_t id;
		_seconds = seconds;
		pthread_create(&id, NULL, _clearIn, this);
		pthread_join(id, NULL); //Needed this to fix a memory leak
		// pthread_create(pthread_t *__restrict __newthread, const pthread_attr_t *__restrict __attr, void *(*__start_routine)(void *), void *__restrict __arg)

		return true;
	}

	static void *_clearIn(void *Aud){
		Auditorium *aud = (Auditorium *)Aud;	//DO NOT DELETE THIS POINTER.
		time_t now = time(NULL);
		while(time(NULL) - now != aud->_seconds){}
		aud->tryLock();
		aud->clear();
		aud->unlock();
		return NULL;
	}


	/*! Clears the auditorium in n seconds.
	*/
	virtual void clear() = 0;

	/*! Used to enable/disable Booking strategies..
	*/
	void enableBookingStrategies(){
		if( !strategy ){
			strategy = new Booking();
			strategy->setAuditorium(this);
		}
	}

	/*! Used to make bookings via strategies..
	\param group: The group to make the booking for.
	\param type: The kind of strategy to use for the booking.
	\returns true/false whether the booking worked.
	*/
	bool bookStrat(Group *group, short type){
		strategy->setStrategy(type);
		return strategy->canBook(group);
	}
	size_t rows;
	size_t columns;
    private:
	bool _mutex;
	AuditoriumMemento *memento;
	TicketPrinter *printer;
	Booking *strategy;
      std::string name;
	size_t _seconds;
};


#endif

//Auditoriums dump to files not to save people , but  rather to save a template of itself.
