//! A class for storing objects in a vector using the STL
/*!
  Provides an interface for classes which need to store large numbers of elements.
*/
#ifndef LISTASVECTOR_H
#define LISTASVECTOR_H
#include "List.h"
#include <vector>
class ListAsVector : public List{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~ListAsVector();
      ListAsVector();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
      void push_back(Object *object);
      void pop_back();
      Object *at(size_t i);
      void setCurrent(Object *object);
      Object *getCurrent();
      void add(Object *object);
      void next(); /**< Iterates to the next instance of Object in Container*/
      void previous();
      bool isAtEnd();
      size_t getSize();

      //Unique Variables
private:
      //Unique Variables
      std::vector<Object *> *objectVector;
      Object *current;
      size_t nCurrent;
};
#endif
