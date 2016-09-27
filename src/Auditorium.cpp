/*!
 * Auditorium:
 * Abstract class which allows me to implement the three
 * other auditorium classes.
 */

#include "Auditorium.h"
Auditorium::~Auditorium(){

}

Auditorium::Auditorium(){

}

//Overloaded Functions
bool Auditorium::isNull(void) const{
	return 1; //Marker:Unsure
}

int Auditorium::compare(Object const &) const{
	return 1; //Marker:Unsure
}

void Auditorium::print(std::ostream &out) const{
	out << "Marker:Unsure";
}

std::string Auditorium::getId() const{
	return "Auditorium";
}

int Auditorium::compareTo(Object const &) const{
	return 1; //Marker:Unsure
}

void Auditorium::setState( size_t , size_t , short ){
	return; //empty declaration
}
