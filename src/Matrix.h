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
      virtual void add(Object *object) = 0; /**< Adds an Object to the matrix.*/
      virtual bool setValue(size_t row , size_t column ,short s) = 0; /**< Sets the value located at row <-> column to value.*/
      virtual Seat *getValue(size_t row , size_t column) = 0; /**< Compares two instances of Object.*/
      //Virtual Functions
      virtual Object *at(size_t row, size_t column) = 0; /**< Returns the object at i.*/
      virtual void next() = 0; /**< Iterates to the next instance of Object in Container*/
      virtual void previous() = 0; /**<Iterates to the previous instance of Object in Container*/
      virtual void push_back(Object *object) = 0; /**< Adds an Object to the list.*/
      virtual void pop_back() = 0; /**< Removes an Object from the list.*/
      virtual void setCurrent(Object *object) = 0;
      virtual bool isAtEnd() = 0; /**<Returns true when the end of the Container has been reached. */
      
      virtual Object *getCurrent() = 0;/**< Returns the current object pointer (or cursor if you will).*/
};
#endif
