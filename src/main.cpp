/*
Connor Armand Du Plooy
u16169532
*/
#include <iostream>
#include "Object.h"
#include "NullObject.h"
#include "Integer.h"

#include "List.h"
#include "ListAsVector.h"
#include "ListAsDynamicArray.h"

using namespace std;

int main(){
      NullObject a;

      Integer b = 3;

      ListAsDynamicArray *d = new ListAsDynamicArray();
      d->push_back(&b);
      d->push_back(&a);
      d->pop_back();




      d->at(d->getSize())->print(cout);
      delete d;
      return 0;
}
