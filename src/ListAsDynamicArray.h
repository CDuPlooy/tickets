/*
Connor Armand Du Plooy
u16169532
*/

#ifndef LISTASDYNAMICARRAY_H
#define LISTASDYNAMICARRAY_H
//Defines
#define DEF_CHUNK_SIZE 1 //Change the default chunk size for the dynamic array.
#include "List.h"

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
      void grow();
      size_t getSize();
private:
      Object **objectPointers;
      size_t objectCount;
      size_t chunkSize;
};
#endif
