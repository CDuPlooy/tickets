#include "Pensioner.h"
Pensioner::~Pensioner(){

}

Pensioner::Pensioner(){

}

//Overloaded Functions
bool Pensioner::isNull(void) const{
	return false;
}

int Pensioner::compare(Object const &) const{
	return 1;
}

void Pensioner::print( std::ostream &out ) const{
	out << "Pensioner";
}

std::string Pensioner::getId() const{
	return "Pensioner";
}

int Pensioner::compareTo(Object const &) const{
	return 1;
}
