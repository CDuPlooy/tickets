#include "Minor.h"
Minor::~Minor(){

}

Minor::Minor(){

}

//Overloaded Functions
bool Minor::isNull(void) const{
	return false;
}

int Minor::compare(Object const &) const{
	return 1;
}

void Minor::print( std::ostream &out ) const{
	out << "Minor";
}

std::string Minor::getId() const{
	return "Minor";
}

int Minor::compareTo(Object const &) const{
	return 1;
}
