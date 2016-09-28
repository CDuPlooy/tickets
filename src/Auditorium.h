//!  An abstract class.
/*!
  An abstract class which provides an interface to the different types of auditoriums.
*/

#ifndef AUDITORIUM_H
#define AUDITORIUM_H
#include "Object.h"
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
      virtual bool book(size_t , size_t) = 0;
      virtual void cancelBooking(size_t , size_t ) = 0;
      virtual bool findFree(size_t &, size_t &) = 0;
      virtual bool checkBoundry( size_t , size_t ) = 0;
      virtual bool setVoid(size_t , size_t , size_t , bool ) = 0;
      virtual bool bookAdv(size_t size) = 0;
      virtual void setState( size_t , size_t , short ) = 0;
      virtual std::string dumpRaw() = 0;
private:
      short seating; //Fixed , variable or flexible
};
#endif
