#ifndef CONTAINER_H
#define CONTAINER_H
#include "Object.h"
class Container{
public:
      Container();
      ~Container();
      Object *getCurrent();

      virtual void add(Object *object) = 0;
      virtual void next() = 0;
      virtual void previous() = 0;
      Object *current;
};
#endif
