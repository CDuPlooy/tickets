#include "AuditoriumMemento.h"

int AuditoriumMemento::compareTo(Object const &) const{
	return 1;
}


//Constructors
AuditoriumMemento::~AuditoriumMemento(){

}

AuditoriumMemento::AuditoriumMemento(){
	auditorium = NULL;
}

//Overloaded Functions
bool AuditoriumMemento::isNull(void) const{
	return false;
}

int AuditoriumMemento::compare(Object const &) const{
	return 1;
}

void AuditoriumMemento::print(std::ostream &out) const{
	out << "AuditoriumMemento";
}

std::string AuditoriumMemento::getId() const{
	return  "AuditoriumMemento";
}

void AuditoriumMemento::bind(Auditorium *auditorium){
	this->auditorium = auditorium;
}
