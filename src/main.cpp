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
      d->push_back(&a);
      cout << d->getSize() << std::endl;
      delete d;
      return 0;
}
