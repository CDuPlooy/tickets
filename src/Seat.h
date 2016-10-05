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
      void setState(short state); /**< Sets the seat state.*/
      short getState(); /**< Returns the seat state..*/
      void bind(Person *aPerson); /**< Binds a person to a seat.*/
      Person *getPerson(); /**< Returns the person associated with the seat.*/
private:
      short state;
      Person *person;
};


#endif
