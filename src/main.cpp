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
#include "FixedSizeMatrix.h"
#include "DynamicAuditorium.h"
#include "FixedAuditorium.h"
#include "Container.h"

using namespace std;

int main(){

      dynamicAuditorium da(10,10);
      da.setVoid(0, 0, 10);
      da.setVoid(8, 0, 10);
      da.setVoid(1, 2, 2);
      da.setVoid(3, 8, 2);
      da.book(0, 2);
      da.book(0,6);
      da.book(1,1);
      da.print(cout);
      return 0;
}
