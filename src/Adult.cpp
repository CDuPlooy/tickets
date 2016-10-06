#include "Adult.h"
#include <sstream>
Adult::~Adult(){

}

Adult::Adult(){

}

//Overloaded Functions
bool Adult::isNull(void) const{
	return false;
}


int Adult::compare(Object const &) const{
	return 1;
}

void Adult::print( std::ostream &out ) const{
	out << "Adult";
}

std::string Adult::getId() const{
	return "Adult";
}

int Adult::compareTo(Object const &) const{
	return 1;
}

std::string Adult::toString(){
	std::stringstream buffer;
	buffer <<  "Name:" << getName() << " Age:" << getAge() << " Fee:" << getFee();
	return buffer.str();
}
