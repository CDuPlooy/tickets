#include "DynamicAuditorium.h"
int dynamicAuditorium::compareTo(Object const &) const{
	return 1; //Marker:Unsure
}
//Constructors
dynamicAuditorium::dynamicAuditorium(size_t _rows , size_t _columns){
	seats = 0;
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

dynamicAuditorium::~dynamicAuditorium(){
	for(size_t i = 0 ; i < rows ; i++){
			delete [] data[i];
		}
	delete [] data;
}

//Overloaded Functions
bool dynamicAuditorium::isNull(void) const{
	return false;
}
int dynamicAuditorium::compare(Object const &) const{
	return 1; //Marker:Unsure
}

void dynamicAuditorium::print(std::ostream &out) const{
	for(size_t i = 0 ; i < rows ; i++){
		for(size_t j = 0 ; j < columns ; j++){
			if( data[i][j] == SEAT_EMPTY )
				out << "[0] ";
			else if ( data[i][j] == SEAT_TAKEN )
				out << "[X] ";
			else if ( data[i][j] == SEAT_VOID )
				out << "    ";
		}
	out << std::endl;
	}
}

std::string dynamicAuditorium::getId() const{
	return "dynamicAuditorium";
}
//Unique Functions
bool dynamicAuditorium::book( size_t r , size_t c ){
	if(!checkBoundry(r, c))
		return false;

	if( data[r][c] == SEAT_TAKEN )
		return false;
	else{
		data[r][c] = SEAT_TAKEN;
		seats++;
	}
	return true;
}


bool dynamicAuditorium::findFree(size_t &r, size_t &c){
	for(size_t i = 0 ; i < rows ; i++)
		for(size_t j = 0 ; j < columns ; j++)
			if(data[i][j] == SEAT_EMPTY){
				r = i;
				c =j;
				return true;
			}
		return false;
}

void dynamicAuditorium::cancelBooking(size_t r , size_t c ){
	if(!checkBoundry(r, c))
		return;
	data[r][c] = SEAT_EMPTY;
}

bool dynamicAuditorium::checkBoundry( size_t r, size_t c){
	if( r > rows )
		return false;
	if( c > columns )
		return false;
	if( data[r][c] == SEAT_VOID )
		return false;
	return true;
}

bool dynamicAuditorium::setVoid(size_t r, size_t c, size_t s){
	for( size_t i = 0 ; i < s ; i++ ){
		if(checkBoundry(r , c + i))
			data[r][c + i] = SEAT_VOID;
		else
			return false;
	}

	return true;
}
