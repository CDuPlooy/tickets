//!  An abstract class.
/*!
  Provides an interface for classes which need to store large numbers of elements.
*/
#ifndef LIST_H
#define LIST_H
#include "Object.h"
#include "Container.h"
class List : public Container{
protected:
      int compareTo(Object const &) const =0;
public:
      //Constructors
      ~List();
      List();
      //Overloaded Functions
      bool isNull(void) const = 0;
      int compare(Object const &) const = 0;
      void print(std::ostream & = std::cout) const = 0;
      std::string getId() const = 0;
      //Unique Functions (To List)
};
#endif


//TODO: Notice how everything inhereting from list is one dimensional and everything from matrix is two dimensional.
