#include "DynamicSizeMatrix.h"

int DynamicSizeMatrix::compareTo(Object const &) const{
	return 1;
}

DynamicSizeMatrix::~DynamicSizeMatrix(){

}

DynamicSizeMatrix::DynamicSizeMatrix(size_t rows){
	for( size_t i = 0 ; i < rows ; i++ )
		data.push_back(new ListAsSLL());
}

bool DynamicSizeMatrix::isNull(void) const{
	return false;
}

int DynamicSizeMatrix::compare(Object const &) const{
	return 1;
}

void DynamicSizeMatrix::print(std::ostream &out) const{
	out << "DynamicSizeMatrix";
}

std::string DynamicSizeMatrix::getId() const{
	return "DynamicSizeMatrix";
}

void DynamicSizeMatrix::add(Object *object){

}

void DynamicSizeMatrix::next(){

}

void DynamicSizeMatrix::previous(){

}

void DynamicSizeMatrix::push_back(Object *object) {

}

void DynamicSizeMatrix::pop_back(){

}

void DynamicSizeMatrix::setCurrent(Object *object){

}

Object *DynamicSizeMatrix::getCurrent(){

}

Object *DynamicSizeMatrix::at(size_t row, size_t column){

}
 /**< Returns the object at i.*/
bool DynamicSizeMatrix::isAtEnd(){

}
 /**<Returns true when the end of the Container has been reached. */
