//!  An abstract class.
/*!
  An abstract class which provides an interface to the different types of lists and matrixes.
*/
#ifndef CONTAINER_H
#define CONTAINER_H
#include "Object.h"

//Class
class Container : public Object{
protected:
            int compareTo(Object const &) const;
public:
      Container();
      ~Container();

	/*! Gets the current object / cursor
	\return An object pointer or a cursror.
	*/
      virtual Object *getCurrent() = 0;

	/*! Gets the current object / cursor
	\return An object pointer or a cursror.
	*/
      virtual void add(Object *object) = 0;

	/*! Sets the cursor to the next object.
	*/
      virtual void next() = 0;

	/*! Sets the cursor to the previous  object.
	*/
	virtual void previous() = 0;

	/*! Adds an object to the Container.
	\param object: A pointer to an Object.
	*/
	virtual void push_back(Object *object) = 0;

	/*! Removes an object * from the top of the Container.
	*/
	virtual void pop_back() = 0;


	Object *current; /**<A pointer to an Object instance. */

	/*! Determines whether the cursor is at the end of the Container.
	\return Returns true when the cursor is at the end of the Container.
	*/
	virtual bool isAtEnd() = 0;
      //Inheritance from object
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
};
#endif
