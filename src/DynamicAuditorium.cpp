#include "DynamicAuditorium.h"
#include "cColours.h"
#include "Seat.h"

int DynamicAuditorium::compareTo(Object const &) const{
	return 1; //Marker:Unsure
}
//Constructors
DynamicAuditorium::DynamicAuditorium(size_t _rows , size_t _columns){
	seats = 0;
	fa = new FixedSizeMatrix( _rows , _columns );
}

DynamicAuditorium::~DynamicAuditorium(){
	delete fa;
}

//Overloaded Functions
bool DynamicAuditorium::isNull(void) const{
	return false;
}
int DynamicAuditorium::compare(Object const &) const{
	return 1; //Marker:Unsure
}

void DynamicAuditorium::print(std::ostream &out) const{
	for(size_t i = 0 ; i < fa->getRows() ; i++){		//Marker:SpecialCase ---> Coloured output might not work for a text box
		for(size_t j = 0 ; j < fa->getColumns() ; j++){
			if( fa->getValue(i,j)->getState()  == SEAT_EMPTY )
				out << RESET "[" BLUE "0" RESET "] ";
			else if ( fa->getValue(i,j)->getState() == SEAT_TAKEN )
				out << RESET "[" RED "X"  RESET "] ";
			else if ( fa->getValue(i,j)->getState()  == SEAT_VOID )
				out << "    ";
		}
	out << std::endl;
	}
}

std::string DynamicAuditorium::getId() const{
	return "DynamicAuditorium";
}
//Unique Functions
bool DynamicAuditorium::book( size_t r , size_t c ){
	if(!checkBoundry(r, c))
		return false;

	if( fa->getValue(r,c)->getState() == SEAT_TAKEN )
		return false;
	else{
		fa->getValue(r, c)->setState(SEAT_TAKEN);
		seats++;
	}
	return true;
}


bool DynamicAuditorium::findFree(size_t &r, size_t &c){
	for(size_t i = 0 ; i < fa->getRows() ; i++)
		for(size_t j = 0 ; j < fa->getColumns() ; j++)
			if(fa->getValue(i,j) == SEAT_EMPTY){
				r = i;
				c =j;
				return true;
			}
		return false;
}

void DynamicAuditorium::cancelBooking(size_t r , size_t c ){
	if(!checkBoundry(r, c))
		return;
	fa->setValue(r,c,SEAT_EMPTY);
}

bool DynamicAuditorium::checkBoundry( size_t r, size_t c){
	if( r > fa->getRows() )
		return false;
	if( c > fa->getColumns() )
		return false;
	if( fa->getValue(r,c)->getState() == SEAT_VOID )
		return false;
	return true;
}

bool DynamicAuditorium::setVoid(size_t r, size_t c, size_t s , bool vertical){		//Modify this function so it can set void in rows too.
	if(vertical){
		for( size_t i = 0 ; i < s ; i++ ){									    //Maybe use a template pattern for this or tag it as one.
			if(checkBoundry(r , c + i))
				fa->getValue(r,c+i)->setState(SEAT_VOID);
			else
				return false;
		}
		return true;
	}
	else{
		for( size_t i = 0 ; i < s ; i++ ){									    //Maybe use a template pattern for this or tag it as one.
			if(checkBoundry(c + i , r))
				fa->getValue(c+i,r)->setState(SEAT_VOID);
			else
				return false;
		}
		return true;
	}
}

void DynamicAuditorium::setState( size_t r, size_t c, short s){
	fa->getValue(r, c)->setState(s);
}

bool DynamicAuditorium::bookAdv(size_t size){
	size_t spaces = 0;

	bool spaceFound = false;
	size_t j;
	size_t i;

	for( i = 0 ; i < fa->getRows() ; i++){
		for(j = 0 ; j < fa->getColumns() ; j++){
			if( fa->getValue(i, j) == SEAT_EMPTY ){
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


std::string DynamicAuditorium::dumpRaw(){
	std::string buffer;
	for(size_t i = 0 ; i < fa->getRows() ; i++){
		for(size_t j = 0 ; j < fa->getColumns() ; j++){ //Marker:SpecialCase ---> Coloured output might not work for a text box
			if(fa->getValue(i,j)->getState() == SEAT_EMPTY )
				buffer.append("[0] ");
			else if (fa->getValue(i,j)->getState() == SEAT_TAKEN )
				buffer.append("[X] ");
			else if (fa->getValue(i,j)->getState() == SEAT_VOID )
				buffer.append("[V] ");	//TEMP
		}
		buffer.push_back('\n');
	}
	return buffer;
}
