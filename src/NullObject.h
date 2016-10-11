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
      ~NullObject();
      NullObject();
public:
      //Constructors
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions

	/*! Gets the singleton.
	\return A NullObject pointer.
	*/
      NullObject* getSingleton();

	/*! Sets the next node.
	\param singleton: The value to set the NullObject to.
	*/
      void setSingleton(NullObject *singleton);
private:
      static NullObject *_singleton;
};
#endif
