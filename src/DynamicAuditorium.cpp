#include "DynamicAuditorium.h"
#include "cColours.h"
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
	for(size_t i = 0 ; i < rows ; i++){		//Marker:SpecialCase ---> Coloured output might not work for a text box
		for(size_t j = 0 ; j < columns ; j++){
			if( data[i][j] == SEAT_EMPTY )
				out << RESET "[" BLUE "0" RESET "] ";
			else if ( data[i][j] == SEAT_TAKEN )
				out << RESET "[" RED "X"  RESET "] ";
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

bool dynamicAuditorium::setVoid(size_t r, size_t c, size_t s , bool vertical){		//Modify this function so it can set void in rows too.
	if(vertical){
		for( size_t i = 0 ; i < s ; i++ ){									    //Maybe use a template pattern for this or tag it as one.
			if(checkBoundry(r , c + i))
				data[r][c + i] = SEAT_VOID;
			else
				return false;
		}
		return true;
	}
	else{
		for( size_t i = 0 ; i < s ; i++ ){									    //Maybe use a template pattern for this or tag it as one.
			if(checkBoundry(c + i , r))
				data[c+i][r] = SEAT_VOID;
			else
				return false;
		}
		return true;
	}
}

void dynamicAuditorium::setState( size_t r, size_t c, short s){
	data[r][c] = s;
}

bool dynamicAuditorium::bookAdv(size_t size){
	size_t spaces = 0;

	bool spaceFound = false;
	size_t j;
	size_t i;

	for( i = 0 ; i < rows ; i++){
		for(j = 0 ; j < columns ; j++){
			if( data[i][j] == SEAT_EMPTY ){
				spaces++;
			}
			else{
				spaces = 0;
				continue;
			}

			if(spaces == size){
				spaceFound = true;
				break;
			}
		}
		if(spaceFound)
			break;
		spaces = 0;
	}

	if(spaceFound)
		for(size_t c = 0  ; c  < size ; c++){
			book(i,j-c);
		}
	return spaceFound;
}


std::string dynamicAuditorium::dumpRaw(){
	std::string buffer;
	for(size_t i = 0 ; i < rows ; i++){
		for(size_t j = 0 ; j < columns ; j++){ //Marker:SpecialCase ---> Coloured output might not work for a text box
			if( data[i][j] == SEAT_EMPTY )
				buffer.append("[0] ");
			else if ( data[i][j] == SEAT_TAKEN )
				buffer.append("[X] ");
		}
		buffer.push_back('\n');
	}
	return buffer;
}
