//!  A wrapper for single linked lists.
/*!
  Provides an interface for classes which need to store large numbers of elements.
*/
#ifndef LISTASSLL_H
#define LISTASSLL_H
#include "Object.h"
#include "List.h"

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

private:
      Object *next;
};
#endif
