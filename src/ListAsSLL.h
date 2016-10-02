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
      //Unique Functions
      void remove(Object *value);  /**< Removes an object from the single linked list.*/
      void dump();  /**< For Debugging only.*/
      //Overloaded from list:
      void add(Object *object);
      void next();
      void previous();
      void push_back(Object *object) ;
      void pop_back();
      Object *at(size_t i);
      virtual void setCurrent(Object *object);
      virtual Object *getCurrent();
private:
      Node *head;
      Object *current;
};
#endif
