//!  An abstract class.
/*!
  A Wrapper for the list objects.
*/
#ifndef MATRIX_H
#define MATRIX_H
#include "Object.h"
#include "Container.h"
#include "Seat.h"

class Matrix : public Container{
public:
      Matrix();
      ~Matrix();

	/*! Adds an object to the data structure.
	\param object: An object pointer.
	*/
      virtual void add(Object *object) = 0;

	/*! Sets the value at a particular position
	\param row: A value representing the row.
	\param column: A value representing the column.
	\param s: The state to set the value to.
	\return true/false whether the function executed correctly.
	*/
      virtual bool setValue(size_t row , size_t column ,short s) = 0;

	/*! gets the value at a particular position
	\param row: A value representing the row.
	\param column: A value representing the column.
	\return A Seat pointer.
	*/
      virtual Seat *getValue(size_t row , size_t column) = 0;
      //Virtual Functions

	/*! Gets the  object at position i.
	\param i: The position of the object in the data structure.
	\return An object pointer.
	*/
      virtual Object *at(size_t row, size_t column) = 0;

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

	/*! Determines whether the cursor is at the end of the Container.
	\return Returns true when the cursor is at the end of the Container.
	*/
      virtual bool isAtEnd() = 0; /**<Returns true when the end of the Container has been reached. */

	/*! Gets the current object / cursor
	\return An object pointer or a cursror.
	*/
      virtual Object *getCurrent() = 0;/**< Returns the current object pointer (or cursor if you will).*/
};
#endif
