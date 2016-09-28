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

      virtual void add(Object *object) = 0;
      virtual void next() = 0;
      virtual void previous() = 0;
      Object *current;

      //Inheritance from object
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
};
#endif
