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
      bool book(Person *person , size_t , size_t);
      void cancelBooking(size_t , size_t );
      bool findFree(size_t &, size_t &);
      bool checkBoundry( size_t , size_t );
      bool setVoid(size_t , size_t , size_t , bool );
      bool bookAdv(Group &group);
      void setState( size_t , size_t , short );
      std::string dumpRaw();
      void dumpFile(std::string filename);
      short getState( size_t row, size_t column);
      Seat *getSeat( size_t row, size_t column);
	Auditorium *clone();
	void clear();



private:
      FixedSizeMatrix *fa;
      size_t seats;

};
#endif
