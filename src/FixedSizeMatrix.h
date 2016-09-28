//!  A fixed size matrix with iterators.
/*!
  Provides an interface to the auditoriums for managing internal data.
*/
#ifndef FIXEDSIZEMATRIX_H
#define FIXEDSIZEMATRIX_H
#include "Object.h"
#include "Matrix.h"
#include "List.h"
#include "ListAsDynamicArray.h"
#include "ListAsVector.h"
class FixedSizeMatrix : public Matrix{
public:
      FixedSizeMatrix(size_t rows , size_t columns);  //A variable which determines what kind of list to use.
      virtual ~FixedSizeMatrix();
      void next();
      void previous();
      void add(Object *obj);
      bool setValue(size_t row , size_t column , short value);
      short getValue(size_t row , size_t column);
      size_t getRows();
      size_t getColumns();
      bool checkBoundry( size_t row, size_t column);
private:
      short **data;
      size_t columns;
      size_t rows;
};
#endif
