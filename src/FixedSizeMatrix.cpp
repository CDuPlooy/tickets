#include <iostream>
#include "Matrix.h"
#include "FixedSizeMatrix.h"
#include "Seat.h"

FixedSizeMatrix::FixedSizeMatrix(size_t _rows , size_t _columns){
	current_x = current_y = 0;
	rows = _rows;
	columns = _columns;
	data = new Seat**[_rows];
	for(size_t i = 0 ; i < _rows ; i++){
		data[i] = new Seat*[_columns];
		for(size_t j = 0 ; j < _columns ; j++){
			data[i][j] = new Seat(NULL);  //Marker:Unsure
		}
	}
	currentl = data[current_x][current_y];
}

FixedSizeMatrix::~FixedSizeMatrix(){
	for(size_t i = 0 ; i < rows ; i++){
			for(size_t j = 0 ; j < columns ; j++){
				delete data[i][j];
			}
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
	//std::cout << row << "<->" << column << std::endl;
	if(!checkBoundry(row, column))
		return false;
	data[row][column]->setState(value);
	return true;
}

Seat *FixedSizeMatrix::getValue(size_t row , size_t column){
	if(!checkBoundry(row, column))
		return NULL;

	return data[row][column];
}

size_t FixedSizeMatrix::getRows(){
	return rows;
}


size_t FixedSizeMatrix::getColumns(){
	return columns;
}

void FixedSizeMatrix::add(Object *obj){
	push_back(obj);
}

void FixedSizeMatrix::next(){
	if( current_x++ > getRows() - 2 ){
		current_y++;
		current_x = 0;
	}
	if( current_y > getColumns() - 1 ){
		current_y = 0;
		current_x = 0;
	}
	currentl = data[current_x][current_y];
 }

void FixedSizeMatrix::previous(){
	if( current_x-- == (size_t)-1 ){
		current_y--;
		current_x = getRows();
	}
	if( current_y == (size_t)-1 ){
		current_y = getColumns();
		current_x = getRows();
	}

}

void FixedSizeMatrix::push_back(Object *object) {
	for(size_t i = 0 ; i < rows ; i++)
			for(size_t j = 0 ; j < columns ; j++)
				if( static_cast<Seat *>(data[i][j])->getPerson() == NULL ){
					delete data[i][j];
					currentl = data[i][j] = (Seat *)object;	//Marker:Dangerous
					static_cast<Seat *>(data[i][j])->bind(static_cast<Seat *>(object)->getPerson());
					return;
				}
}

void FixedSizeMatrix::pop_back(){
	for(size_t i = 0 ; i < rows ; i++)
			for(size_t j = 0 ; j < columns ; j++){
				if( static_cast<Seat *>(data[i][j])->getPerson() == NULL ){
					setValue(i,j-- - 1,SEAT_EMPTY);
					// data[i--][j--] = NULL;
					return;
				}
			}

}

void FixedSizeMatrix::setCurrent(Object *object){
	currentl = object;
}

Object *FixedSizeMatrix::getCurrent(){
	return currentl;
}


Object *FixedSizeMatrix::at(size_t row, size_t column){
	if(!checkBoundry(row, column))
		return NULL;
	return data[row][column];
}

void FixedSizeMatrix::dump(){
	for(size_t i = 0 ; i < rows ; i++){
		for(size_t j = 0 ; j < columns ; j++){
			std::cout << data[i][j]->getState() << " ";
		}
		std::cout << std::endl;
	}
}
