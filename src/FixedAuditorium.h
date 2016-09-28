//!  An auditorium which can be of variable length and width.
/*!
  Assumes length is equal to width.
*/
#ifndef FIXEDAUDITORIUM_H
#define FIXEDAUDITORIUM_H
#include "Object.h"
#include "Auditorium.h"
#include "FixedSizeMatrix.h"
class FixedAuditorium : public Auditorium{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~FixedAuditorium();
      FixedAuditorium(size_t , size_t);
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
      bool bookAdv(size_t);
      void setState( size_t , size_t , short );
      std::string dumpRaw();

private:
      FixedSizeMatrix *fa;
      size_t seats;

};
#endif
