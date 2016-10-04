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
#include "Store.h"
#include "Debug.h"

using namespace std;

int main(){
      cout << "Testing iterator ! " << endl;
      Store *itStore = new Store(CDLL);
      Person *Bob = new Person();
      Seat *BobSeat = new Seat(Bob);
      FixedAuditorium *fixedaud = new FixedAuditorium(5,5);
      itStore->push_back(Bob);
      itStore->push_back(BobSeat);
      itStore->push_back(fixedaud);
      Object *object = itStore->getCurrent();

      while( itStore->isAtEnd() == false ){
            D_MSG(object->getId());
            itStore->next();
            object = itStore->getCurrent();
      }
      cout << "_____________DONE______________" << endl;
      delete itStore;
      delete Bob;
      delete BobSeat;
      delete fixedaud;
      D_PAUSE("Press any key to continue");
      return 0;

      cout << "Testing the Store!" << endl;
      Store *store = new Store(CVECTOR);
      Person *a = new Person();
      Seat *b = new Seat(a);
      store->push_back(a);
      cout << "Person should expand to" << "==>" << store->getCurrent()->getId() << std::endl;
      store->push_back(b);
      store->next();
      cout  << "Seat should expand to" << "==>" << store->getCurrent()->getId() << std::endl;
      store->pop_back();
      store->previous();
      cout << "Person should expand to" << "==>" << store->getCurrent()->getId() << std::endl;

      delete b;
      delete store;
      delete a;
      cout << "_____________DONE______________" << endl;


      cout << "Testing the fixed size matrix!" << endl;
      FixedSizeMatrix *fa = new FixedSizeMatrix(5,5);
      Person person;
      Seat *seat = new Seat(&person);
      seat->bind(&person);
      cout << "\tTesting pushback" << endl;
      fa->push_back(seat);
      fa->pop_back();

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
