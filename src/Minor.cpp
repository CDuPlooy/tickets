#include "Minor.h"
#include <sstream>

Minor::~Minor(){

}

Minor::Minor(){
	setFee(21.5);
	setAge(3);
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

std::string Minor::toString(){
	std::stringstream buffer;
	buffer <<  "Person{Type:" << getId() << " Name:" << getName() << " Age:" << getAge() << " Fee:" << getFee()<<" Person}";
	return buffer.str();
}
