//!  An abstract class.
/*!
  Provides an interface for classes which need to store large numbers of elements.
*/
#ifndef LIST_H
#define LIST_H
#include "Object.h"
class List : public Object{
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
      virtual void push_back(Object *object) = 0;
      virtual void pop_back() = 0;
      virtual Object *at(size_t i) = 0;
};
#endif
