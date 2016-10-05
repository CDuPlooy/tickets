//!  A class used as part of the adapter/iterator patterns.
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
      Object *getCurrent();/**< Returns the current Object pointer or cursor if you will.*/
      void next();/**< Moves the Object pointer to the next element.*/
      void previous(); /**< Moves the Object pointer to the previous element.*/
      void push_back(Object *obj);/**< Wrapper function to Container::push_back()*/
      void pop_back();/**< Wrapper function to Container::pop_back()*/
      bool isAtEnd();/**< Wrapper function to Container::isAtEnd()*/

private:
      Container *container;
};
#endif
