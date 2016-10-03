//!  A fixed size matrix with iterators.
/*!
  Provides an interface to the auditoriums for managing internal data.
*/
#ifndef FIXEDSIZEMATRIX_H
#define FIXEDSIZEMATRIX_H
#include "Object.h"
#include "Matrix.h"
#include "Seat.h"
class FixedSizeMatrix : public Matrix{
public:
      FixedSizeMatrix(size_t rows , size_t columns);  //A variable which determines what kind of list to use.
      virtual ~FixedSizeMatrix();
      bool setValue(size_t row , size_t column , short value);
      Seat *getValue(size_t row , size_t column);
      size_t getRows();  /**< Returns the amount of rows in the current FixedSizeMatrix.*/
      size_t getColumns();  /**< Returns the amount of columns in the current FixedSizeMatrix.*/
      bool checkBoundry( size_t row, size_t column);
      //Implemented from list
       void add(Object *object);
       void next();
       void previous();
       void push_back(Object *object) ;
       void pop_back();
       void setCurrent(Object *object);
       Object *getCurrent();
       Object *at(size_t row, size_t column); /**< Returns the object at i.*/
       //Debug
       void dump();
private:
      Object *currentl;
      size_t current_x;
      size_t current_y;
      Seat ***data;
      size_t columns;
      size_t rows;
};
#endif
