//!  A wrapper for double linked lists.
/*!
  Provides an interface for classes which need to store large numbers of elements.
*/
#ifndef LISTASDLL_H
#define LISTASDLL_H
#include "Object.h"
#include "ListAsSLL.h"
#include "NodeDouble.h"
class ListAsDLL : public ListAsSLL{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~ListAsDLL();
      ListAsDLL();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
      void remove(Object *value);  /**< Removes an object from the single linked list.*/
      void dump();  /**< For Debugging only.*/
      void add(Object *object);
      void next();
      void previous();
      void push_back(Object *object) ;
      void pop_back();
      Object *at(size_t i);
      void setCurrent(Object *object);
      Object *getCurrent();

private:
      NodeDouble *head;
      Object *currentl;
      size_t _size;
};
#endif
