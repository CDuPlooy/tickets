//!  Implementation of minor for person.

#ifndef MINOR_H
#define MINOR_H
#include "Person.h"

class Minor : public Person{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~Minor();
      Minor();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
	std::string toString();
private:

};
#endif
//TODO: Volatile : Implement functionality so that a child cannot book without a parent present, eg book will not work but bookAdv will.
