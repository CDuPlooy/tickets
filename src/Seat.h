//!  A class representing a seat.
/*!
     Internally seats are represented using shorts.
*/

#ifndef SEAT_H
#define SEAT_H
#include "Object.h"
#include "Person.h"

//DEFINES
#define SEAT_EMPTY 0
#define SEAT_TAKEN 1
#define SEAT_VOID 2
//END
//!  Implements seats which will be bound to people.
class Seat : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~Seat();
      Seat(Person *person);
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions

	/*! Sets the state of the Seat.
	\param state: The state to set to.
	*/
      void setState(short state);

	/*! Gets the state of the Seat.
	\return  A short representing the state of the Seat.
	*/
      short getState();

	/*! Binds a Person to a Seat.
	\param aPerson: The Person pointer to bind to.
	*/
      void bind(Person *aPerson);

	/*! Gets the person associated with the seat.
	\return NULL on error ; A Person pointer otherwise.
	*/
      Person *getPerson();

	/*! Sums up the Seat class as a string
	\return A string representation of Seat.
	*/
	std::string toString();
private:
      short state;
      Person *person;
};


#endif
