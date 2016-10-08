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
#include "AuditoriumDeveloper.h"
#include "AuditoriumList.h"
#include "cColours.h"
#include "Minor.h"
#include "Adult.h"
#include "Pensioner.h"
#include "TicketPrinter.h"
#include "Seat.h"
#include "Group.h"
#include "Store.h"
#include "Debug.h"

using namespace std;
bool guiMode;

int main( int argc , char **argv ){
	if(argc <= 1)
		guiMode = 0;
	else
		guiMode = 1;

	cout << RED "tickets - COS121 ;\nGui: " << guiMode << RESET << endl;

	cout << "Testing groups!" << endl;
	Minor *Billy = new Minor();
	Billy->setName("Billy");
	Minor *Timmy = new Minor();
	Timmy->setName("Timmy");
	Minor *Sally = new Minor();
	Sally->setName("Sally");
	Group *group = new Group();
	group->push_back(Billy);
	group->push_back(Timmy);
	group->push_back(Sally);


	FixedAuditorium *Brooklyn = new FixedAuditorium(5,5);
	Brooklyn->enableMemento(true);
	Brooklyn->bookAdv(*group);
	Brooklyn->getMemento()->print(cout);
		Brooklyn->print(cout);
	Brooklyn->undo();
		Brooklyn->print(cout);
	Brooklyn->getMemento()->print(cout);
	Brooklyn->undo();
		Brooklyn->print(cout);
	Brooklyn->undo();
		Brooklyn->print(cout);

	Brooklyn->getMemento()->print(cout);


	Brooklyn->print(cout);

	cout << "_____________DONE______________" << endl;
	delete Billy;
	delete Timmy;
	delete Sally;
	delete group;
	delete Brooklyn;

	cout << "Testing memento!" << endl;
	FixedAuditorium *memAud = new FixedAuditorium(5,5);
	memAud->enableMemento(true);
	Minor *Kathy = new Minor();
	Kathy->setName("Kathy");
	memAud->getMemento()->print(cout);
	memAud->book(Kathy, 0, 0);
	cout << "Making a booking." << endl;
	memAud->getMemento()->print(cout);
	memAud->print(cout);
	cout << "Undo the booking." << endl;
	memAud->undo();
	memAud->undo();
	memAud->getMemento()->print(cout);

	memAud->print(cout);
	cout << "_____________DONE______________" << endl;
	delete memAud;



      cout << "Testing ticket printer!" << endl;
      TicketPrinter *tp = new TicketPrinter();
      FixedAuditorium *faA = new FixedAuditorium(2,2);
      faA->setName("Brooklyn");
      Minor *personA = new Minor();
	personA->setName("Flappy");
      faA->book(personA,0, 0);

      cout << tp->printAuditorium(faA,0,0,false) << endl;

      cout << "_____________DONE______________" << endl;
      delete faA;
      delete tp;
      delete personA;

      cout << "Testing AuditoriumList!" << endl;
      AuditoriumList al;
      FixedAuditorium brooklyn(5,5);
      brooklyn.setName("Brooklyn");
      DynamicAuditorium irene(5,5);
      irene.setName("Irene");

      al.push_back(&brooklyn);
      al.push_back(&irene);
      for(size_t i = 0 ; i < al.getSize() ; i++)
            cout << al.at(i)->getName() << endl;
      cout << "_____________DONE______________" << endl;


      cout << "Testing iterator ! " << endl;
      Store *itStore = new Store(CDLL);
      Minor *Bob = new Minor();
      Seat *BobSeat = new Seat(Bob);
      FixedAuditorium *fixedaud = new FixedAuditorium(5,5);
      itStore->push_back(Bob);
      itStore->push_back(BobSeat);
      itStore->push_back(fixedaud);
      Object *object = itStore->getCurrent();

      while( itStore->isAtEnd() == false ){
      cout << object->getId() << endl;
            itStore->next();
            object = itStore->getCurrent();
      }
      cout << "_____________DONE______________" << endl;
      delete itStore;
      delete Bob;
      delete BobSeat;
      delete fixedaud;


      cout << "Testing the Store!" << endl;
      Store *store = new Store(CVECTOR);
      Person *a = new Minor();
      Seat *b = new Seat(a);
      store->push_back(a);
      cout << "Minor should expand to" << "==>" << store->getCurrent()->getId() << std::endl;
      store->push_back(b);
      store->next();
      cout  << "Seat should expand to" << "==>" << store->getCurrent()->getId() << std::endl;
      store->previous();
      store->pop_back();
      cout << "Minor should expand to" << "==>" << store->getCurrent()->getId() << std::endl;

      delete b;
      delete store;
      delete a;
      cout << "_____________DONE______________" << endl;


      cout << "Testing the fixed size matrix!" << endl;
      FixedSizeMatrix *fa = new FixedSizeMatrix(5,5);
      Minor person;
      Seat *seat = new Seat(&person);
      seat->bind(&person);
      cout << "\tTesting pushback" << endl;
      fa->push_back(seat);
      fa->pop_back();

      fa->dump();
      delete fa;
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
