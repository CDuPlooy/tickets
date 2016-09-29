//!  A wrapper for single linked lists.
/*!
  Provides an interface for classes which need to store large numbers of elements.
*/
#ifndef LISTASSLL_H
#define LISTASSLL_H
#include "Object.h"
#include "List.h"
#include "Node.h"

class ListAsSLL : public List{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~ListAsSLL();
      ListAsSLL();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      void push_back(Object *object){}; /**< Adds an Object to the list.*/
      void pop_back(){}; /**< Removes an Object from the list.*/
      Object *at(size_t i){ return NULL; }; /**< Returns the object at i.*/
      //Unique Functions
      void add(int value);  /**< Adds an object to the single linked list.*/
      void remove(int value);  /**< Removes an object from the single linked list.*/
      void dump();  /**< For Debugging only.*/
private:
      Node *head;
};
#endif
