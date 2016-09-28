#ifndef DYNAMICAUDITORIUM_H
#define DYNAMICAUDITORIUM_H
#include "Object.h"
#include "Auditorium.h"
class dynamicAuditorium : public Auditorium{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~dynamicAuditorium();
      dynamicAuditorium(size_t , size_t);
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
      
private:
      size_t rows , columns;
      size_t seats;
      short **data;
};
#endif
