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
#include "ListAsDLL.h"
#include "ListAsSLL.h"
#include "FixedSizeMatrix.h"
#include "DynamicAuditorium.h"
#include "FixedAuditorium.h"
#include "Container.h"
#include "AuditoriumModeller.h"
#include "cColours.h"
#include "Seats.h"

using namespace std;

int main(){
      // FixedAuditorium fa(5,5);
      // fa.bookAdv(5);
      // fa.bookAdv(5);
      // fa.bookAdv(5);
      // fa.bookAdv(5);
      // fa.bookAdv(5);
      // fa.setState(0, 0, SEAT_VOID);
      // fa.setState(1, 1, SEAT_VOID);
      // fa.setState(2, 2, SEAT_VOID);
      // fa.setState(3, 3, SEAT_VOID);
      // fa.setState(4, 4, SEAT_VOID);
      //
      // cout << fa.dumpRaw() << endl;
      // return 1;
      AuditoriumModeller am;
      am.loadFromFile("test.txt");
      am.getAuditorium()->print(cout);
      cout << am.getAuditorium()->dumpRaw() << endl;
      return 0;
}
