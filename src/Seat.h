//!A class to represent seats inside of auditoriums
/*!
  Seats can be bound to a person , a seat's state should also be set when it is bound to a person.
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
      void setState(short state); /**< Sets the seat state.*/
      short getState(); /**< Returns the seat state..*/
      void bind(Person *aPerson); /**< Binds a person to a seat.*/
private:
      short state;
      Person *person;
};


#endif
