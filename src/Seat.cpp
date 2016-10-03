#include "Seat.h"
#include "Debug.h"
int Seat::compareTo(Object const &seat) const{
	return 1;
}

Seat::~Seat(){

}

Seat::Seat(Person *person){
	state = SEAT_EMPTY;
	this->person = person;
}
//Overloaded Functions

bool Seat::isNull(void) const{
	return false;
}

int Seat::compare(Object const &) const{
	return 1;
}

void Seat::print(std::ostream &out) const{
	out << "Seat: " << std::endl << "State: " << state << std::endl;
}

std::string Seat::getId() const{
	return "Seat";
}

Person *Seat::getPerson(){
	return person;
}

void Seat::setState(short state){
	this->state = state;
}

short Seat::getState(){
	return state;
}

void Seat::bind(Person *aPerson){
	person = aPerson;
	setState(SEAT_TAKEN);
}
