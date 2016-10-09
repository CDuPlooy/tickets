#ifndef DYNAMICSIZEMATRIX_H
#define DYNAMICSIZEMATRIX_H
#include "Object.h"
#include "ListAsSLL.h"
#include "Seat.h"
#include <vector>
 class DynamicSizeMatrix : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      DynamicSizeMatrix(size_t rows );
      ~DynamicSizeMatrix();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
	void add(Object *object);
	void next();
	void previous();
	void push_back(Object *object) ;
	void pop_back();
	void setCurrent(Object *object);
	Object *getCurrent();
	Object *at(size_t row, size_t column); /**< Returns the object at i.*/
	bool isAtEnd(); /**<Returns true when the end of the Container has been reached. */
private:
	std::vector<ListAsSLL *> data;
	Object *currentl;
};
#endif
