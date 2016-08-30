/*
Connor Armand Du Plooy
u16169532
*/

#ifndef LISTASDYNAMICARRAY_H
#define LISTASDYNAMICARRAY_H
#include "Object.h"

class NullObject : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~NullObject();
      NullObject();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions

private:

};
#endif
