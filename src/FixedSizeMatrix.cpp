#include "Matrix.h"
#include "FixedSizeMatrix.h"
#include "Seats.h"

FixedSizeMatrix::FixedSizeMatrix(size_t _rows , size_t _columns){
	rows = _rows;
	columns = _columns;
	data = new short*[_rows];
	for(size_t i = 0 ; i < _rows ; i++){
		data[i] = new short[_columns];
		for(size_t j = 0 ; j < _columns ; j++){
			data[i][j] = SEAT_EMPTY;
		}
	}
}

FixedSizeMatrix::~FixedSizeMatrix(){
	for(size_t i = 0 ; i < rows ; i++){
			delete [] data[i];
		}
	delete [] data;
}
bool FixedSizeMatrix::checkBoundry( size_t row, size_t column){
	if( row > rows )
		return false;
	if( column > columns )
		return false;

	return true;
}
bool FixedSizeMatrix::setValue(size_t row , size_t column , short value){
	if(!checkBoundry(row, column))
		return false;
	data[row][column] = value;
	return true;
}

short FixedSizeMatrix::getValue(size_t row , size_t column){
	if(!checkBoundry(row, column))
		return false;

	return data[row][column];
}

size_t FixedSizeMatrix::getRows(){
	return rows;
}

size_t FixedSizeMatrix::getColumns(){
	return columns;
}

void FixedSizeMatrix::add(Object *obj){

}

void FixedSizeMatrix::next(){

}

void FixedSizeMatrix::previous(){

}

void FixedSizeMatrix::push_back(Object *object) {

}

void FixedSizeMatrix::pop_back(){

}

Object *FixedSizeMatrix::at(size_t i){
	return NULL;
}
