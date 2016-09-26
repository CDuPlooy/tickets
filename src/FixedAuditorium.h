#ifndef FIXEDAUDITORIUM_H
#define FIXEDAUDITORIUM_H
#include "Object.h"
#include "Auditorium.h"
class fixedAuditorium : public Auditorium{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~fixedAuditorium();
      fixedAuditorium(size_t , size_t);
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
      bool bookAdv(size_t);

private:
      size_t rows , columns;
      size_t seats;
      short **data;
};
#endif
