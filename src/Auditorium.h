#ifndef AUDITORIUM_H
#define AUDITORIUM_H
#include "Object.h"
//Defines
#define SEAT_VOID 0
#define SEAT_EMPTY 1
#define SEAT_TAKEN 2

//Class
class Auditorium : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~Auditorium();
      Auditorium();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
      bool book(size_t , size_t);
      void cancelBooking(size_t , size_t );
      bool findFree(size_t &, size_t &);
      bool checkBoundry( size_t , size_t );
      bool setVoid(size_t , size_t , size_t , bool );
      bool  bookAdv(size_t size);
      void setState( size_t , size_t , short );
private:
      short seating; //Fixed , variable or flexible
};
#endif
