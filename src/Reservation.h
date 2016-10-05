//!  Reservations for the auditoriums

#ifndef RESERVATION_H
#define RESERVATION_H
#include "Object.h"
class Reservation : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~Reservation();
      Reservation();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions

private:

};
#endif
