//!  An object used to represent a seat which has no person.
#ifndef NULLPERSON_H
#define NULLPERSON_H
#include "NullObject.h"

class NullPerson : public NullObject{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~NullPerson();
      NullPerson();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions

private:

};
#endif
