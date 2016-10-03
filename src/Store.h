#ifndef STORE_H
#define STORE_H
#include "Object.h"
#include "Container.h"
//Defines
#define CSLL 0
#define CDLL 1
#define CVECTOR 2
#define CDYNARR 3
//Classes
class Store : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~Store();
      Store( short choice );
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
      //Iterator Functions
      Object *getCurrent();
      void next();
      void previous();
      void push_back(Object *obj);
      void pop_back();

private:
      Container *container;
};
#endif
