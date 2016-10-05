#include <iostream>
#include <fstream>
#include "cColours.h"
#include "FixedAuditorium.h"
#include "Seat.h"
FixedAuditorium::FixedAuditorium(size_t _rows , size_t _columns){
	seats = 0;
	fa = new FixedSizeMatrix( _rows , _columns );
}

FixedAuditorium::~FixedAuditorium(){
	delete fa;
}
//Overloaded Functions
bool FixedAuditorium::isNull(void) const{
	return false;
}
int FixedAuditorium::compare(Object const &) const{
	return 1; //Marker unsure
}
void FixedAuditorium::print(std::ostream &out)  const{
	for(size_t i = 0 ; i < fa->getRows() ; i++){
		for(size_t j = 0 ; j < fa->getColumns() ; j++){ //Marker:SpecialCase ---> Coloured output might not work for a text box
			if( fa->getValue(i,j)->getState() == SEAT_EMPTY )
				out << RESET "[" BLUE "0" RESET "] ";
			else if ( fa->getValue(i,j)->getState() == SEAT_TAKEN )
				out << RESET "[" RED "X"  RESET "] ";
				else if ( fa->getValue(i,j)->getState() == SEAT_VOID )
						out << "    ";
		}
	out << std::endl;
	}
}
void FixedAuditorium::setState( size_t r, size_t c, short s){
	if(!fa->checkBoundry(r, c))
		return;
	fa->getValue(r , c)->setState(s);
}

bool FixedAuditorium::book(size_t r, size_t c){
	if(!fa->checkBoundry(r, c))
		return false;

	if(fa->getValue(r,c)->getState() == SEAT_TAKEN)
		return false;
	else{
		fa->getValue(r , c)->setState(SEAT_TAKEN);
		seats++;
	}
	return true;
}

bool FixedAuditorium::setVoid(size_t r, size_t c, size_t s , bool vertical){		//Modify this function so it can set void in rows too.
	if(vertical){
		for( size_t i = 0 ; i < s ; i++ ){									    //Maybe use a template pattern for this or tag it as one.
			if(checkBoundry(r , c + i))
				fa->getValue(r , c + i)->setState(SEAT_VOID);
			else
				return false;
		}
		return true;
	}
	else{
		for( size_t i = 0 ; i < s ; i++ ){									    //Maybe use a template pattern for this or tag it as one.
			if(checkBoundry(c + i , r))
				fa->getValue(c+i , r)->setState(SEAT_VOID);
			else
				return false;
		}
		return true;
	}
}

int FixedAuditorium::compareTo(Object const &) const{
	return 1; //Marker:Unsure
}

std::string FixedAuditorium::getId() const{
	return "FixedAuditorium";
}

bool FixedAuditorium::findFree(size_t &r, size_t &c){
	for(size_t i = 0 ; i < fa->getRows() ; i++)
		for(size_t j = 0 ; j < fa->getColumns() ; j++)
			if(fa->getValue(i, j)->getState() == SEAT_EMPTY){
				r = i;
				c =j;
				return true;
			}
		return false;
}

void FixedAuditorium::cancelBooking(size_t r , size_t c ){
	if(!checkBoundry(r, c))
		return;
	fa->getValue(r , c )->setState(SEAT_EMPTY);
}

bool FixedAuditorium::checkBoundry( size_t r, size_t c){
	return fa->checkBoundry(r , c);
}

bool FixedAuditorium::bookAdv(size_t size){

	size_t spaces = 0;

	bool spaceFound = false;
	size_t j;
	size_t i;

	for( i = 0 ; i < fa->getRows() ; i++){
		for(j = 0 ; j < fa->getColumns() ; j++){
			if( fa->getValue(i, j)->getState() == SEAT_EMPTY ){
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

std::string FixedAuditorium::dumpRaw(){
	std::string buffer;
	for(size_t i = 0 ; i < fa->getRows() ; i++){
		for(size_t j = 0 ; j < fa->getColumns() ; j++){ //Marker:SpecialCase ---> Coloured output might not work for a text box
			if( fa->getValue(i,j)->getState() == SEAT_EMPTY )
				buffer.append("[0] ");
			else if ( fa->getValue(i,j)->getState() == SEAT_TAKEN )
				buffer.append("[X] ");
				else if ( fa->getValue(i,j)->getState()  == SEAT_VOID )
					buffer.append("[V] ");
		}
		buffer.push_back('\n');
	}
	return buffer;
}

void FixedAuditorium::dumpFile(std::string filename){
	std::ofstream fs(filename.c_str());
	fs << dumpRaw();
	fs.close();
}
short FixedAuditorium::getState( size_t row, size_t column){
	if(!checkBoundry(row, column))
		return SEAT_VOID;
	else
		return fa->getValue(row,column)->getState();
}


Seat *FixedAuditorium::getSeat( size_t row, size_t column){
		if(!checkBoundry(row, column))
			return NULL;
		else
			return fa->getValue(row, column);
		}
