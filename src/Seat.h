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
      void setState(short state);
      short getState();

private:
      short state;
      Person *person;
};


#endif
