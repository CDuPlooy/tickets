/*
Connor Armand Du Plooy
u16169532
*/
#include <iostream>
#include "tickets_includes.h"

using namespace std;
bool guiMode;

void testCases(){
		cout << "PENDING" << endl;

}
void pauseC(){
	cout << "Press <e> followed by enter to continue the demo!" << endl;
	char a;
	cin >> a;
	system("clear");
	cout << "* * * * Time passes . . . * * * * " << endl << endl;
}

void dayOne(){
	cout << "DAY 1: " << endl;
	cout << "SterKinekor wants to develop a new 5x5 auditorium , let's use the auditorium developer to create and save one."  << endl;
	AuditoriumDeveloper audDev;
	Auditorium *aud = audDev.construct(AUD_FIXED, 5	, 5);
	aud->print(cout);
	aud->dumpFile(".DynamicStandard.raw");
	cout << "Perfect ! The auditorium has been saved for yet another day." << endl;
	pauseC();
	delete aud;

}

void dayTwo(){
	cout << "DAY 2: " << endl;
	cout << "Management likes the new auditorium design , they want you to load it as an active template! Let's try the auditorium modeller" << endl;
	AuditoriumModeller audMod;
	if(!audMod.loadFromFile(".DynamicStandard.raw")){
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

	pauseC();
	cout << "Someone else wants to book a ticket at 3x3!" << endl;
	aud->book(Timmy, 3, 3);
	aud->print(cout);
	cout << "Ah! Darn kids , always messing with the clerks , luckily we can cancel an operation!" << endl;
	aud->cancelBooking(3,3);
	aud->print(cout);
	pauseC();
	delete Mandy;
	delete Timmy;
	delete aud;

}

void dayThree(){
	cout << "You come into the auditorium to find that someone has broken an entire row of seats!" << endl;
	cout << "We'll need to disable row 3 of  the auditorium" << endl;
	DynamicAuditorium *dAud = new DynamicAuditorium(5,5);
	dAud->setVoid(3, 0, 5, true);
	dAud->print(cout);
	cout << endl << "Bookings are now more complicated, let's have the system assign free spaces to people!" << endl;
	Pensioner *Nia = new Pensioner;
	size_t x;
	size_t y;
	dAud->findFree(x, y);
	cout << "The system found an empty seat at " << x << ":" << y << endl;
	dAud->book(Nia, x, y);
	dAud->findFree(x, y);
	dAud->print(cout);
	cout << "Another customer wants to book!" << endl;
	cout << "The system found an empty seat at " << x << ":" << y << endl;
	dAud->book(Nia, x, y);
	dAud->print(cout);
	delete dAud;
	pauseC();
	delete Nia;

}

void dayFour(){
	cout << "DAY 4: " << endl;
	cout << "Management has requested the system support a sort of plugin. Luckily we used the decorator pattern!" << endl;
	DynamicAuditorium *dAud = new DynamicAuditorium(5,5);
	Pensioner *Nia = new Pensioner();
	cout << "Press continue to see the new functionality ( random bookings will be  made but a TicketPrinter will print beautiful tickets )" << endl;
	pauseC();
	dAud->enableMemento(true);
	dAud->enablePrinter(true);
	dAud->setName("Brooklyn");

	Nia->setName("Nia");
	dAud->book(Nia, 0, 0);
	Nia->setName("Melly");

	dAud->book(Nia, 1, 0);
	Nia->setName("Billy");

	dAud->book(Nia, 0, 3);
	Nia->setName("Timmy");

	dAud->book(Nia, 4, 0);
	Nia->setName("Chris");

	dAud->book(Nia, 0, 2);
	Nia->setName("Stephan");

	dAud->print(cout);
	cout << "We can now even undo bookings!" << endl;
	dAud->undo();
	dAud->print(cout);

	delete dAud;
	pauseC();
	delete Nia;

	pauseC();
}

void dayFive(){
	cout << "DAY 5 : " << endl;
	cout << "Miraculously , the franchise has gotten bigger!" << endl;
	cout << "We should organise auditoriums in the same complexes together!" << endl;
	AuditoriumList AudList;
	FixedAuditorium fa(2,4);
	fa.setName("Subgroup A");
	FixedAuditorium faOne(14,14);
	faOne.setName("Subgroup B");
	FixedAuditorium faTwo(5,5);
	faTwo.setName("Subgroup C");
	AudList.push_back(&fa);
	AudList.push_back(&faOne);
	AudList.push_back(&faTwo);



	for(size_t i = 0 ; i < AudList.getSize() ; i++){
		cout << i + 1 << ".) " << AudList.at(i)->getName() << endl;
		AudList.at(i)->print(cout);
	}
	pauseC();

}

void daySix(){
	cout << "DAY 6: " << endl;
	cout << "Management wants auditoriums to be able to clear themselves after a specified amount of time!" << endl;
	cout << "Luckily we linked to the pthread library!" << endl;
	DynamicAuditorium *dAud = new DynamicAuditorium(5,5);
	Pensioner *Nia = new Pensioner;
	dAud->book(Nia, 0, 2);
	dAud->print(cout);
	dAud->clearIn(5);
	cout << "The current movie is really short , the auditorium should be cleared in 5 seconds!" << endl;
	sleep(6);
	dAud->print(cout);
	delete dAud;
	delete Nia;
	pauseC();
}

void daySeven(){
cout << "DAY 7:" << endl;
cout << "Larry wants to book a seat , but he has bad eye sight. Luckily we have different strategies for customers with different needs." << endl;
FixedAuditorium fa(5,5);
Pensioner *Larry = new Pensioner();
Group group;
Larry->setName("Larry");
group.push_back(Larry);
fa.enablePrinter(true);
fa.bookStrat(&group, BOOK_BEST_VIEW);
fa.print(cout);
delete Larry;
}

void demo(){
	dayOne();
	dayTwo();
	dayThree();
	dayFour();
	dayFive();
	daySix();
	daySeven();
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



	cout << "Welcome to the demo version of tickets! Press <s> for the demo/case examples or press <d> for debugging tests" << endl;
	demo();
	cout << "Thank you for looking at the tickets demo!" << endl;
      return 0;
}
