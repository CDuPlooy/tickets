/*
Connor Armand Du Plooy
u16169532
*/
#include <iostream>
#include "tickets_includes.h"

using namespace std;
bool guiMode;

void testCases(){
			cout << "Testing ticket printer!" << endl;
		      FixedAuditorium *faA = new FixedAuditorium(2,2);
			faA->enablePrinter(true);
		      faA->setName("Brooklyn");
		      Minor *personA = new Minor();
			personA->setName("Flappy");
		      faA->book(personA,0, 0);

		      cout << "_____________DONE______________" << endl;
		      delete faA;
		      delete personA;

		//
		// cout << "Testing the flexi matrix" << endl;
		// FlexiAuditorium *flex = new FlexiAuditorium(3,3);
		// // flex->fillRand();
		// // flex->print(cout);
		// // cout << "Can iterate bot : " << flex->iterateBot(0,1) << endl;
		// // cout << "Can iterate top : " << flex->iterateTop(0,1) << endl;
		// //
		// // cout << "Can iterate left : " << flex->iterateLeft(0,1) << endl;
		// // cout << "Can iterate right : " << flex->iterateRight(0,1) << endl;
		// //
		// // cout << "_____________DONE______________" << endl;
		// delete flex;
		// return 0;

		cout << "Testing the dynamicAuditorium" << endl;
		FixedAuditorium *dynAud = new FixedAuditorium(5,5);
		Minor *Darky = new Minor();
		dynAud->enableMemento(true);
		// dynAud->getMemento()->guiMode = false;
		dynAud->book(Darky, 0, 0);
		dynAud->print(cout);

		dynAud->undo();
		dynAud->print(cout);
		dynAud->print(cout);


		delete dynAud;
		delete Darky;
		cout << "_____________DONE______________" << endl;
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

}
void pause(){
	cout << "Press <e> followed by enter to continue the demo!" << endl;
	char a;
	cin >> a;
	system("clear");
}

void dayOne(){
	cout << "DAY 1: " << endl;
	cout << "SterKinekor wants to develop a new 5x5 auditorium , let's use the auditorium developer to create and save one."  << endl;
	AuditoriumDeveloper audDev;
	Auditorium *aud = audDev.construct(AUD_FIXED, 5	, 5);
	aud->print(cout);
	aud->dumpFile("DynamicStandard.raw");
	cout << "Perfect ! The auditorium has been saved for another day." << endl;
	pause();
	delete aud;
	cout << "* * * * Time passes . . . * * * * " << endl << endl;
}

void dayTwo(){
	cout << "DAY 2: " << endl;
	cout << "Management likes the new auditorium design , they want you to load it as an active template! Let's try the auditorium modeller" << endl;
	AuditoriumModeller audMod;
	if(!audMod.loadFromFile("DynamicStandard.raw")){
		cout << "Unexpected error during demo ; What did you do? " << endl;
		exit(1);
	}
	Auditorium *aud = audMod.getAuditorium();
	cout << "Look! A charming family would like to buy ticktes!" << endl;
	Group group;
	Adult *Mandy = new Adult();
	Adult *Timmy = new Adult();
	group.push_back(Mandy);
	group.push_back(Timmy);

	aud->bookAdv(group);
	aud->print(cout);

	pause();
	cout << "Someone else wants to book a ticket at 3x3!" << endl;
	aud->book(Timmy, 3, 3);
	aud->print(cout);
	cout << "Ah! Darn kids , alwats messing with the clerks , luckily we can cancel an operation!" << endl;
	aud->cancelBooking(3,3);
	aud->print(cout);
	pause();
	delete Mandy;
	delete Timmy;
	delete aud;
	cout << "* * * * Time passes . . . * * * * " << endl << endl;

}

void dayThree(){
	cout << "You come into the auditorium to find that someone has broken an entire row of seats!" << endl;
	cout << "We'll need to disable row 3 of  the auditorium" << endl;
	DynamicAuditorium dAud(5,5);
	dAud.setVoid(3, 0, 5, true);
	dAud.print(cout);
	cout << endl << "Bookings are now more complicated, let's have the system assign free spaces to people!" << endl;
	Pensioner *Nia = new Pensioner;
	size_t x;
	size_t y;
	dAud.findFree(x, y);
	cout << "The system found an empty seat at " << x << ":" << y << endl;
	dAud.book(Nia, x, y);
	dAud.findFree(x, y);
	dAud.print(cout);
	cout << "Another customer wants to book!" << endl;
	cout << "The system found an empty seat at " << x << ":" << y << endl;
	dAud.book(Nia, x, y);
	dAud.print(cout);
	pause();
	delete Nia;
	cout << "* * * * Time passes . . . * * * * " << endl << endl;

}

void dayFour(){
	cout << "DAY 4: " << endl;
	cout << "Management has requested the system support a sort of plugin. Luckily we used the decorator pattern!" << endl;
	FixedAuditorium dAud(5,5);
	Pensioner *Nia = new Pensioner;
	cout << "Press continue to see the new functionality ( random bookings will be  made but a TicketPrinter will print beautiful tickets )" << endl;
	pause();
	dAud.enableMemento(true);
	dAud.enablePrinter(true);
	dAud.setName("Brooklyn");

	Nia->setName("Nia");
	dAud.book(Nia, 0, 0);
	Nia->setName("Melly");

	dAud.book(Nia, 1, 0);
	Nia->setName("Billy");

	dAud.book(Nia, 0, 3);
	Nia->setName("Timmy");

	dAud.book(Nia, 4, 0);
	Nia->setName("Chris");

	dAud.book(Nia, 0, 2);
	Nia->setName("Stephan");

	dAud.print(cout);
	cout << "We can now even undo bookings!" << endl;
	dAud.undo();
	dAud.print(cout);


	pause();
	delete Nia;

	pause();		//TODO: Double check memento implementation , specifically undo order.
	cout << "* * * * Time passes . . . * * * * " << endl << endl;
}
void demo(){
	dayOne();
	dayTwo();
	dayThree();
	dayFour();
	//TODO: dayFive , show off AuditoriumLists.
}

void testMemento(){
	FlexiAuditorium fa(3,3);
	fa.enableMemento(true);
	Minor *billy = new Minor();
	fa.book(billy, 0, 0);
	fa.print(cout);
	fa.getMemento()->print(cout);
	fa.undo();
	fa.print(cout);
	fa.getMemento()->print(cout);
	delete billy;
}
int main( int argc , char **argv ){
	// testMemento();

	demo();

	cout << "This concludes the CLI demo of tickets , to run the debug tests press <d> , to exit press <e>" << endl;
	char decision;
	cin >> decision;
	if(decision == 'd')
		testCases();
      return 0;
}


//TODO: Implement a demo with the given code.
//TODO: Add vector<size_t> to the memento so undo can work on undo adv.
//TODO: Add strategies to bookAdv
//TODO: Implement clone methods for auditoriums.
//TODO: FIX MEMENTO2
