//!  An auditorium which can be of variable length and width.
/*!
  Really is just a clone of fixed auditorium.
*/
#ifndef DynamicAuditorium_H
#define DynamicAuditorium_H
#include "Object.h"
#include "Auditorium.h"
#include "FixedSizeMatrix.h"
class DynamicAuditorium : public Auditorium{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~DynamicAuditorium();
      DynamicAuditorium(size_t , size_t);
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
      std::string dumpRaw();
      void dumpFile(std::string filename);

private:
      FixedSizeMatrix *fa;
      size_t seats;
};
#endif
