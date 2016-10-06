//!  Implementation of pensioner for person.

#ifndef PENSIONER_H
#define PENSIONER_H
#include "Person.h"

class Pensioner : public Person{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~Pensioner();
      Pensioner();
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
