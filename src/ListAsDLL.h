#ifndef LISTASDLL_H
#define LISTASDLL_H
#include "Object.h"

class ListAsDLL : public List{
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

private:
      Object *next;
      Object *prev;
};
#endif
