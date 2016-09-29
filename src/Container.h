//!  An abstract class.
/*!
  An abstract class which provides an interface to the different types of lists and matrixes.
*/
#ifndef CONTAINER_H
#define CONTAINER_H
#include "Object.h"
class Container : public Object{
protected:
            int compareTo(Object const &) const;
public:
      Container();
      ~Container();
      Object *getCurrent();

      virtual void add(Object *object) = 0; /**< Adds an object to the container */
      virtual void next() = 0; /**< Iterates to the next instance of Object in Container*/
      virtual void previous() = 0; /**<Iterates to the previous instance of Object in Container*/
      virtual void push_back(Object *object) = 0; /**< Adds an Object to the list.*/
      virtual void pop_back() = 0; /**< Removes an Object from the list.*/
      virtual Object *at(size_t i) = 0; /**< Returns the object at i.*/
      Object *current; /**<A pointer to an Object instance. */

      //Inheritance from object
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
};
#endif
