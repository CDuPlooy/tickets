#ifndef LISTASDYNAMICARRAY_H
#define LISTASDYNAMICARRAY_H
//Defines
#define DEF_CHUNK_SIZE 1 //Change the default chunk size for the dynamic array.
#include "List.h"
//!  An Implementation of STL vectors used for storing Objects.
class ListAsDynamicArray : public List{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~ListAsDynamicArray();
      ListAsDynamicArray();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions (Unique to list)
      void push_back(Object *object);
      void pop_back();
      Object *at(size_t i);
      //Unique Functions (Unique to ListAsDynamicArray)
      void grow(); /**< Grows the dynamic array by doubling it's size.*/
      size_t getSize();  /**< Returns the size of the array.*/
      void add(Object *object);
      void next();
      void previous();
      void setCurrent(Object *object);
      Object *getCurrent();
private:
      Object **objectPointers;
      size_t objectCount;
      size_t chunkSize;
      size_t nCurrent;
};
#endif
