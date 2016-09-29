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
      //Overloaded from list
      void push_back(Object *object){}; /**< Adds an Object to the list.*/
      void pop_back(){}; /**< Removes an Object from the list.*/
      Object *at(size_t i){return NULL; }; /**< Returns the object at i.*/
      //Unique Functions
      void add(int value);  /**< Adds an object to the single linked list.*/
      void remove(int value);  /**< Removes an object from the single linked list.*/
      void dump();  /**< For Debugging only.*/

private:
      NodeDouble *head;
};
#endif
