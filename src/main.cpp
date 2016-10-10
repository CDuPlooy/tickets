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
		DynamicAuditorium *dynAud = new DynamicAuditorium(5,5);
		Minor *Darky = new Minor();
		dynAud->enableMemento(true);
		// dynAud->getMemento()->guiMode = false;
		dynAud->book(Darky, 0, 0);
		dynAud->print(cout);

		dynAud->undo();
		dynAud->print(cout);
		dynAud->getDsm()->print(cout);


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
int main( int argc , char **argv ){
	//TEST 1
	cout << "This is a demo of the tickets application!" << endl;
	cout << "Day 1:" << endl;

	cout << "SterKinekor has different kinds of auditoriums and would like to save templates for these auditoriums." << endl;
	cout << "The first template is a 5x5 auditorium." << endl;
	cout << "The system uses a Modeller to build a 5x5 auditorium." << endl;
	AuditoriumModeller audMod;

	Auditorium *aud = audMod.construct(AUD_DYNAMIC, 5, 5);
	aud->print(cout);

	aud->dumpFile("DynamicStandard.raw");
	cout << endl  << "Unfortunately , SterKinekor will not be receiving any customers today , let's save the auditorium as a template!" << endl << endl;
	pause();
	//TEST 2
	cout << "Day 2:" << endl;
	cout << "Look , some customers are arriving! We should load a template auditorium using the auditorium developer :D " << endl;
	delete aud;

	AuditoriumDeveloper audDev;
	if ( !audDev.loadFromFile("DynamicStandard.raw") ){
		cout << "Couldn't load the auditorium!" << endl;
		return 1;
	}
	aud = audDev.getAuditorium();
	aud->enableMemento(true);
	
	aud->setName("Brooklyn");
	cout << "Let's see if it loaded correctly!" << endl;
	aud->print(cout);
	cout << endl << "A Pensioner named Randy wants to book a ticket. We should enable the ticketPrinter to automate the printing as bookings are made!" << endl;
	Pensioner *Randy = new Pensioner;
	Randy->setName("Randy");
	aud->enablePrinter(true);
	aud->book(Randy, 0, 0);
	cout << "Let's update the display!" << endl;
	aud->print(cout);


	pause();

	//TEST 3
	cout << "Randy is forgetful , he doesn't want to see a movie anymore! He cancels his ticket." << endl;;
	aud->cancelBooking(0, 0);
	aud->print(cout);
	delete Randy;

	cout << "A charming family wants to see a movie! They need 4 seats - and next to each other!" << endl;
	Group *group = new Group;
	Adult *Billy = new Adult();
	Billy->setName("Billy");
	Adult *Mandy = new Adult();
	Mandy->setName("Mandy");
	Minor *Grimmy = new Minor();
	Grimmy->setName("Grimmy");
	Minor *Tod = new Minor();
	Tod->setName("Tod");


	group->push_back(Billy);
	group->push_back(Mandy);
	group->push_back(Grimmy);
	group->push_back(Tod);
	aud->bookAdv(*group);
	aud->print(cout);

	//TEST 4
	cout << "Another family wants to book! Fortunately they have the exact same names as the previous family. However , the second isle is now under maintenance!" << endl;
	aud->guiMode = false;
	aud->setVoid(1, 0, 5, true);
	aud->bookAdv(*group);
	aud->print(cout);

	Adult *Ben = new Adult;
	Ben->setName("Ben");
	cout << "The auditorium is getting full! People might want to cancel bookings. Enable memento to use this functionality." << endl;
	cout << "People are having trouble finding their own open spaces , let's provide them with free seats!" << endl;
	size_t x , y;
	aud->findFree(x, y);
	cout << "The system found a free spot at " << x << ' ' << y << endl;
	aud->book(Ben, x, y);
	aud->print(cout);
	pause();

	//TEST 5
	std::cout << "A clerk messed up and needs to undo an operation! Let's call memento!" << std::endl;
	aud->undo();
	aud->print(cout);
	delete group;
	delete Billy;
	delete Mandy;
	delete Ben;
	delete Grimmy;
	delete Tod;

	delete aud;

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
