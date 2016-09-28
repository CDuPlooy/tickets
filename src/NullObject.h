//!  A class which is used to determine of an object exists / has been initialised.
/*!
  This class is a singleton
*/
#ifndef NULLOBJECT_H
#define NULLOBJECT_H
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
      NullObject* getSingleton();/**< Returns the only instance of NullObject allowed.*/
      void setSingleton(NullObject *singleton); /**< Sets the instance of the NullObject ; This is part of the singleton implementation*/
private:
      static NullObject *_singleton;
};
#endif
