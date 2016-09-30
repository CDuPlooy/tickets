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
#include "Seat.h"

using namespace std;

int main(){
      cout << "Testing the fixed size matrix!" << endl;
      FixedSizeMatrix fa(5,5);
      fa.setValue(0, 0, SEAT_TAKEN);
      fa.setValue(0, 1, SEAT_VOID);
      fa.dump();
      cout << "_____________DONE______________" << endl;

      cout << "Testing the fixed auditorium!" << endl;
      DynamicAuditorium fixedaudit(5,5);
      fixedaudit.bookAdv(5);
      fixedaudit.book(1, 1);
      fixedaudit.setVoid(0, 0, 3, false);
      fixedaudit.print(cout);
      std::cout << fixedaudit.dumpRaw() << std::endl;
      cout << "_____________DONE______________" << endl;


      cout << "Testing the auditorium modeller!" << endl;
      AuditoriumModeller am;
      am.loadFromFile("test.txt");
      am.getAuditorium()->print(cout);
      cout << am.getAuditorium()->dumpRaw() << endl;
      cout << "_____________DONE______________" << endl;

      return 0;
}
