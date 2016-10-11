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
	/*! Constructs a fixed size matrix.
	\param rows: The number of rows.
	\param columns: The number of columns.
	\return A fixed size matrix.
	*/
      FixedSizeMatrix(size_t rows , size_t columns);  //A variable which determines what kind of list to use.
      virtual ~FixedSizeMatrix();
      bool setValue(size_t row , size_t column , short value);
      Seat *getValue(size_t row , size_t column);

	/*! Returns the number of rows in the structure.
	\return The number of rows,
	*/
	size_t getRows();
	/*! Returns the number of columns in the structure.
	\return The number of columns,
	*/
	size_t getColumns();

	bool checkBoundry( size_t row, size_t column);
      //Implemented from list
       void add(Object *object);
       void next();
       void previous();
       void push_back(Object *object) ;
       void pop_back();
       void setCurrent(Object *object);
       Object *getCurrent();
       Object *at(size_t row, size_t column);
       bool isAtEnd();

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
