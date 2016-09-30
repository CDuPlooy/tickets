//!  An abstract class.
/*!
  A Wrapper for the list objects.
*/
#ifndef MATRIX_H
#define MATRIX_H
#include "Object.h"
#include "Container.h"

class Matrix : public Container{
public:
      Matrix();
      ~Matrix();
      virtual void next() = 0;       /**< Gets the next instance of an Object.*/
      virtual void previous() = 0; /**< Gets the previous instance of an Object.*/
      virtual void add(Object *object) = 0; /**< Adds an Object to the matrix.*/
      virtual bool setValue(size_t row , size_t column , short value) = 0; /**< Sets the value located at row <-> column to value.*/
      virtual short getValue(size_t row , size_t column) = 0; /**< Compares two instances of Object.*/
      //Virtual Functions
      virtual Object *at(size_t row, size_t column) = 0; /**< Returns the object at i.*/
};
#endif
