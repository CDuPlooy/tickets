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
      //Virtual functions
      virtual Object *at(size_t i) = 0; /**< Returns the object at i.*/
      virtual void add(Object *object) = 0; /**< Adds an object to the container */
      virtual void next() = 0; /**< Iterates to the next instance of Object in Container*/
      virtual void previous() = 0; /**<Iterates to the previous instance of Object in Container*/
      virtual void push_back(Object *object) = 0; /**< Adds an Object to the list.*/
      virtual void pop_back() = 0; /**< Removes an Object from the list.*/
      virtual void setCurrent(Object *object) = 0;
      virtual Object *getCurrent() = 0;
      //Unique Functions (To List)
};
#endif


//TODO: Notice how everything inhereting from list is one dimensional and everything from matrix is two dimensional.
