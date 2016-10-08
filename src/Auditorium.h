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
#include "AuditoriumMemento.h"
//Class
class Auditorium : public Object{
protected:
      int compareTo(Object const &) const;  /**< Compares two instances of Object.x*/
public:
      //Constructors
      ~Auditorium(); /**< Constructs the Auditorium class.*/
      Auditorium();  /**< Destroys the Auditorium class.*/
      //Overloaded Functions
      bool isNull(void) const;     /**< Checks if a function is an instance of NullObject. */
      int compare(Object const &) const; /**< Used to compare different Auditoriums. */
      void print(std::ostream & = std::cout) const; /**< Generates output for a stream , using std::cout as the default. */
      std::string getId() const;    /**< Returns a string representing the ID/Type of an object. */

      //Unique Functions
      std::string getName(){
          return name;
      }

      void setName(std::string name){
          this->name = name;
      }
      //Pure Virtual Functions
      virtual bool book(Person *person , size_t row, size_t column) = 0;    /**< Creates a booking at row <-> column. */
      virtual void cancelBooking(size_t row, size_t column) = 0; /**< Cancels a booking at row <-> column.  */
      virtual bool findFree(size_t &row, size_t &column) = 0; /**< Finds a free space at row <-> column or forwards.*/
      virtual bool checkBoundry( size_t row, size_t column) = 0; /**< Checks if row <-> column is inside the boundries of the class. */
      virtual bool setVoid(size_t row, size_t column, size_t n, bool vertical) = 0; /**< Disables seats at row <-> column for n elements. false enables vertical set while true enables horisontal set.*/
      virtual bool bookAdv(Group &group ) = 0; /**< Checks if n seats are free and books them. */
      virtual void setState( size_t row, size_t column, short value ) = 0; /**< Sets row <-> column to value. */
      virtual short getState( size_t row, size_t column) = 0; /**<Returns the state of a particular seat.*/
      virtual Seat *getSeat( size_t row, size_t column) = 0; /**<Returns the seat at x,y.*/
      virtual std::string dumpRaw() = 0; /**< Dumps the data table without additional colour codes*/
      virtual void dumpFile(std::string filename) = 0; /**< Dumps the auditorium to a file.*/
	//Part of the memento implementation.
	void enableMemento(bool value); /**< Disable or enables memento.*/
	bool mementoLinked();
	void createMemento();  /**< Creates a memento.*/
	void deleteMemento();  /**< Destroys a memento.*/
	AuditoriumMemento *getMemento();  /**< Returns a memento.*/
	void add_command(std::string); /**< Adds a command to the list.*/
	void undo(); /**< Removes the command at the top of the list and executes it.*/
	

    private:
	AuditoriumMemento *memento;
      std::string name;
};
#endif

//Auditoriums dump to files not to save people , but  rather to save a template of itself.
