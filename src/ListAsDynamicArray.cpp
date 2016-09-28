#include "ListAsDynamicArray.h"
#include "FixedSizeMatrix.h"
#include <iostream> //Marker:Remove on release
using namespace std;//Marker:Remove on release
//Constructors
ListAsDynamicArray::~ListAsDynamicArray(){
      delete [] this->objectPointers;
}
ListAsDynamicArray::ListAsDynamicArray(){
      this->objectCount = 0;
      this->chunkSize = DEF_CHUNK_SIZE;

      this->objectPointers = new Object *[DEF_CHUNK_SIZE];
      for(size_t i = 0 ; i < DEF_CHUNK_SIZE ; i++){
            this->objectPointers[i] = NULL; //set these pointers to null.
      }
}
//Overloaded Functions
size_t ListAsDynamicArray::getSize(){
      return this->objectCount-1;
}

void ListAsDynamicArray::grow(){
      Object **new_pnter = new Object*[this->chunkSize*2];
      size_t i;
      for(i = 0 ; i < this->objectCount ; i++)
            new_pnter[i] = this->objectPointers[i];
      for(i++ ; i < this->chunkSize * 2 ; i++)
            new_pnter[i] = NULL;

      delete [] this->objectPointers;
      this->chunkSize *= 2;
      this->objectPointers = new_pnter;
}


int ListAsDynamicArray::compareTo(Object const &) const{
      return -1; //Marker:Unsure
}
bool ListAsDynamicArray::isNull(void) const{
      return false;
}
int ListAsDynamicArray::compare(Object const &) const{
      return -1; //Marker:Unsure
}
void ListAsDynamicArray::print(std::ostream &out) const{
      out << "ListAsDynamicArray (" << this << ")\n";
      out << "Elements: " << this->objectCount << std::endl;
}
std::string ListAsDynamicArray::getId() const{
      return "ListAsDynamicArray";
}
//Unique Functions
void ListAsDynamicArray::push_back(Object *object){
      if(this->objectCount == this->chunkSize)
            grow();
      this->objectPointers[this->objectCount++] = object;
}
void ListAsDynamicArray::pop_back(){
      this->objectPointers[this->objectCount-1] = NULL;
      this->objectCount--;
}

Object *ListAsDynamicArray::at(size_t i){
      if(i <= this->objectCount)
            return this->objectPointers[i];
      return NULL;
}
