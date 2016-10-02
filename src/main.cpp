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
      FixedSizeMatrix *fa = new FixedSizeMatrix(5,5);
      fa->setValue(0, 0, SEAT_TAKEN);
      fa->setValue(0, 1, SEAT_VOID);
      fa->dump();
      delete fa;
      cout << "_____________DONE______________" << endl;

      cout << "Testing the fixed auditorium!" << endl;
      DynamicAuditorium *fixedaudit = new DynamicAuditorium(5,5);
      fixedaudit->bookAdv(5);
      fixedaudit->book(1, 1);
      fixedaudit->setVoid(0, 0, 3, false);
      fixedaudit->print(cout);
      std::cout << fixedaudit->dumpRaw() << std::endl;
      delete fixedaudit;
      cout << "_____________DONE______________" << endl;


      cout << "Testing the auditorium modeller!" << endl;
      AuditoriumModeller *am = new AuditoriumModeller();
      am->loadFromFile("test.txt");
      am->getAuditorium()->print(cout);
      cout << am->getAuditorium()->dumpRaw() << endl;
      am->getAuditorium()->dumpFile("Raw.txt");
      cout << "_____________DONE______________" << endl;
      delete am;

      cout << "Testing ListAsVector!" << endl;
      ListAsSLL *lv = new ListAsSLL();
      lv->add(lv);
      lv->add(lv);
      lv->add(lv);
      lv->previous();
      cout << lv->getCurrent()->getId() << endl;
      delete lv;
      cout << "_____________DONE______________" << endl;

      return 0;
}
