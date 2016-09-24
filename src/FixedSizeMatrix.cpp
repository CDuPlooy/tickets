#include "Matrix.h"
#include "FixedSizeMatrix.h"

void FixedSizeMatrix::next(){

}

void FixedSizeMatrix::previous(){

}

FixedSizeMatrix::FixedSizeMatrix(short choice , size_t size){
      if(choice == 0)
            list = new ListAsDynamicArray();
      else if(choice == 1)
            list = new ListAsVector();
      
}

FixedSizeMatrix::FixedSizeMatrix(){
      FixedSizeMatrix(0,5);
}

FixedSizeMatrix::~FixedSizeMatrix(){
      delete list;
}

void FixedSizeMatrix::add(Object *object){
      list->push_back(object);
}
