//!  Implementation of adult for person.

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
      //Unique Functions'

	/*! Converts the class to a string.
    \return A std::string representation of the class..  
*/
	std::string toString();


private:

};
#endif
