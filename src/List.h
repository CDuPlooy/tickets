//!  An abstract class.
/*!
  Provides an interface for classes which need to store large numbers of elements.
*/
#ifndef LIST_H
#define LIST_H
#include "Object.h"
#include "Container.h"
class List : public Container{
protected:
      int compareTo(Object const &) const =0;
public:
      //Constructors
      ~List();
      List();

      //Overloaded Functions
      bool isNull(void) const = 0;
      int compare(Object const &) const = 0;
      void print(std::ostream & = std::cout) const = 0;
      std::string getId() const = 0;
      //Virtual functions

	/*! Gets the  object at position i.
	\param i: The position of the object in the data structure.
	\return An object pointer.
	*/
      virtual Object *at(size_t i) = 0;

	/*! Adds an object to the data structure.
	\param object: An object pointer.
	*/
	virtual void add(Object *object) = 0;

	/*! Moves the cursor to the next object.
	*/
      virtual void next() = 0;

	/*! Moves the cursor to the previous object.
	*/
      virtual void previous() = 0;

	/*! Adds an object to the List.
	\param object: A pointer to an Object.
	*/
      virtual void push_back(Object *object) = 0;

	/*! Removes an object * from the top of the List.
	*/
      virtual void pop_back() = 0;

	/*! Sets the cursor.
	\param object: The object pointer to set the cursor to.
	*/
      virtual void setCurrent(Object *object) = 0;


	/*! Gets the current object / cursor
	\return An object pointer or a cursror.
	*/
      virtual Object *getCurrent() = 0;

	/*! Determines whether the cursor is at the end of the Container.
	\return Returns true when the cursor is at the end of the Container.
	*/
      virtual bool isAtEnd() = 0;

      //Unique Functions (To List)
};
#endif
