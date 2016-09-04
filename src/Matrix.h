#ifndef MATRIX_H
#define MATRIX_H
#include "Object.h"
#include "Container.h"

class Matrix : public Container{
public:
      Matrix();
      ~Matrix();
      virtual void next() = 0;
      virtual void previous() = 0;
      virtual void add(Object *object) = 0;
};
#endif
