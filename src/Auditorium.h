#ifndef AUDITORIUM_H
#define AUDITORIUM_H
#include "Object.h"
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
private:
      short seating; //Fixed , variable or flexible
};
#endif
