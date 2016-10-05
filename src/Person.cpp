#include "Person.h"

int Person::compareTo(Object const &) const{
	return 1;
}

//Constructors
Person::~Person(){

}

Person::Person(){

}

//Overloaded Functions
bool Person::isNull(void) const{
	return false;
}

int Person::compare(Object const &) const{
	return 1;
}

void Person::print(std::ostream &out) const{
	out << "Person";
}

std::string Person::getId() const{
	return "Person";
}

void Person::setRow(size_t row){
	this->row = row;
}

void Person::setColumn(size_t column){
	this->column = column;
}

void Person::setAge(unsigned short age){
	this->age = age;
}

size_t Person::getRow(){
	return row;
}

size_t Person::getColunn(){
	return column;
}

float Person::getFee(){
	return fee;
}

void Person::setFee(float fee){
	this->fee = fee;
}
