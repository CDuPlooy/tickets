/**
 * \class DynamicSizeMatrix

 * \brief A matrix which is dynamically sized using STL vectors.

 */
#ifndef DYNAMICSIZEMATRIX_H
#define DYNAMICSIZEMATRIX_H
#include "Object.h"
#include "ListAsSLL.h"
#include "Seat.h"
#include "Matrix.h"
#include <vector>
 class DynamicSizeMatrix : public Matrix{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
	/*! Constructs a dynamic size matrix.
	\param rows: The number of rows.
	\param columns: The number of columns.
	\return A dynamic size matrix.
	*/
      DynamicSizeMatrix(size_t rows , size_t columns);
      ~DynamicSizeMatrix();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
	size_t getRows();
	size_t getColumns();
	/*! Sets the number of columns.
	\param _columns: The number of columns.
	*/
	void setColumns(size_t _columns);
	void add(Object *object);
	void next();
	void previous();
	void push_back(Object *object) ;
	void pop_back();
	void setCurrent(Object *object);
	Object *getCurrent();
	Object *at(size_t row, size_t column);
	bool isAtEnd();
	Seat *getValue(size_t row , size_t column);
	bool setValue(size_t row , size_t column ,short s);
private:
	std::vector< std::vector<Seat *> > data;
	Object *currentl;
	size_t columns;
	size_t rows;
	size_t current_x;
	size_t current_y;
};
#endif
