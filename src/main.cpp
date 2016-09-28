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
#include "AuditoriumModeller.h"
#include "cColours.h"

using namespace std;

int main(){
      fixedAuditorium fa(10,10);
      fa.book(0, 2);
      fa.book(0, 2);
      fa.book(1, 2);
      fa.bookAdv(9);
      fa.print(cout);

      return 0;
}
