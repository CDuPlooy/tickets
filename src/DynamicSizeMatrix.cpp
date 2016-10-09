#include "DynamicSizeMatrix.h"
#include "Debug.h"

int DynamicSizeMatrix::compareTo(Object const &) const{
	return 1;
}

DynamicSizeMatrix::~DynamicSizeMatrix(){
	for( size_t x = 0 ; x < rows ; x++ ){
		for( size_t y = 0 ; y < columns ; y++ ){
			delete data[x][y];
		}
	}
}

DynamicSizeMatrix::DynamicSizeMatrix( size_t rows , size_t columns ){
	data.resize(rows);
	this->rows = rows;
	this->columns = columns;
	current_x = current_y = 0;


	for( size_t x = 0 ; x < rows ; x++ ){
		for( size_t y = 0 ; y < columns ; y++ ){
			data[x].push_back(new Seat(NULL));
		}
	}
	currentl = data[0][0];
}

void DynamicSizeMatrix::setColumns(size_t _columns){
	columns = _columns;
}

bool DynamicSizeMatrix::isNull(void) const{
	return false;
}

int DynamicSizeMatrix::compare(Object const &) const{
	return 1;
}

bool DynamicSizeMatrix::setValue(size_t row , size_t column ,short s){
	data[row][column]->setState(s);
	return true;
}

void DynamicSizeMatrix::print(std::ostream &out) const{
	for( size_t x = 0 ; x < rows ; x++ ){
		for( size_t y = 0 ; y < columns ; y++){
			out << "[ " << data[x][y]->getState() << " ] ";
		}
		out << std::endl;
	}
}

std::string DynamicSizeMatrix::getId() const{
	return "DynamicSizeMatrix";
}

void DynamicSizeMatrix::add(Object *object){
	for(size_t i = 0 ; i < rows ; i++)
			for(size_t j = 0 ; j < columns ; j++)
				if( static_cast<Seat *>(data[i][j])->getPerson() == NULL ){
					delete data[i][j];
					currentl = data[i][j] = (Seat *)object;	//Marker:Dangerous
					static_cast<Seat *>(data[i][j])->bind(static_cast<Seat *>(object)->getPerson());
					return;
				}
}

void DynamicSizeMatrix::next(){
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


void DynamicSizeMatrix::previous(){
	if( current_x-- == (size_t)-1 ){
		current_y--;
		current_x = getRows();
	}
	if( current_y == (size_t)-1 ){
		current_y = getColumns();
		current_x = getRows();
	}

}

void DynamicSizeMatrix::push_back(Object *object) {
	add(object);
}

void DynamicSizeMatrix::pop_back(){
	return; //Empty  implementation for DynamicSizeMatrix
}

void DynamicSizeMatrix::setCurrent(Object *object){
	currentl = object;
}

Object *DynamicSizeMatrix::getCurrent(){
	return currentl;
}

Object *DynamicSizeMatrix::at(size_t row, size_t column){
	return data[row][column];
}
 /**< Returns the object at i.*/
bool DynamicSizeMatrix::isAtEnd(){
	return true;
}
 /**<Returns true when the end of the Container has been reached. */


 size_t DynamicSizeMatrix::getRows(){
	 return rows;
 }

 size_t DynamicSizeMatrix::getColumns(){
	 return columns;
 }

 Seat *DynamicSizeMatrix::getValue(size_t row , size_t column){

	 return (Seat *)at(row,column);
 }
