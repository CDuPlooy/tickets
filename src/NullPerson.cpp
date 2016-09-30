#include "NullPerson.h"
int NullPerson::compareTo(Object const &) const{
	return 1;
}

//Constructors
NullPerson::~NullPerson(){

}

NullPerson::NullPerson(){

}

//Overloaded Functions
bool NullPerson::isNull(void) const{
	return true;
}

int NullPerson::compare(Object const &) const{
	return 1;
}

void NullPerson::print(std::ostream &out) const{
	out << "NullPerson";
}

std::string NullPerson::getId() const{
	return "NullPerson";
}

//Unique Functions
