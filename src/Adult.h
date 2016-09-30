#ifndef ADULT_H
#define ADULT_H
#include "Person.h"

class Adult : public Person{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~Adult();
      Adult();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions

private:

};
#endif
