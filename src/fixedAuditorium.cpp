#include <iostream>
#include "fixedAuditorium.h"

fixedAuditorium::fixedAuditorium(size_t size){
	_size = size;

}

fixedAuditorium::~fixedAuditorium(){

}
//Overloaded Functions
bool fixedAuditorium::isNull(void) const{
	return 1; //Marker unsure
}
int fixedAuditorium::compare(Object const &) const{
	return 1; //Marker unsure
}
void fixedAuditorium::print(std::ostream &out)  const{
	out << "Marker:Unsure" << std::endl;
}
