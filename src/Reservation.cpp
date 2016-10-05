#include "Reservation.h"
Reservation::~Reservation(){

}

Reservation::Reservation(){

}

//Overloaded Functions
bool Reservation::isNull(void) const{
	return false;
}

int Reservation::compare(Object const &) const{
	return 1;
}

void Reservation::print(std::ostream &out) const{
	out << "Reservation";
}

std::string Reservation::getId() const{
	return "Reservation";
}

int Reservation::compareTo(Object const &) const{
	return 1;
}

//Unique Functions
