//!  Models flexi auditoriums.
#include <fstream>
#include <sstream>
#include "Debug.h"
#include "FlexiAuditorium.h"
#include "cColours.h"
#include "Seat.h"


int FlexiAuditorium::compareTo(Object const &) const{
	return 1; //Marker:Unsure
}
//Constructors
FlexiAuditorium::FlexiAuditorium(size_t _rows , size_t _columns){
	seats = 0;
	fa = new DynamicSizeMatrix( _rows , _columns );
	rows = _rows;
	columns = _columns;
}


FlexiAuditorium::~FlexiAuditorium(){
	delete fa;
}

//Overloaded Functions
bool FlexiAuditorium::isNull(void) const{
	return false;
}
int FlexiAuditorium::compare(Object const &) const{
	return 1; //Marker:Unsure
}

void FlexiAuditorium::print(std::ostream &out) const{
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

std::string FlexiAuditorium::getId() const{
	return "FlexiAuditorium";
}
//Unique Functions
bool FlexiAuditorium::book(Person *person ,  size_t r , size_t c ){
	tryLock();
	if(!checkBoundry(r, c)){
		unlock();
		return false;
	}

	if( fa->getValue(r,c)->getState() == SEAT_TAKEN ){
		unlock();
		return false;
	}
	else{
		fa->getValue(r, c)->setState(SEAT_TAKEN);
		fa->getValue(r, c)->bind(person);
		seats++;
		if(mementoLinked()){
			std::string buffer("book ");
			std::stringstream ss;
			buffer.append(person->toString());
			buffer.append(fa->getValue(r , c)->toString());
			buffer.append("Matrix{");
			ss << "Row:" << r << " Column:" << c << " Matrix}";
			buffer.append(ss.str());
			add_command(buffer);
		}
	}
	unlock();
	return true;
}


void FlexiAuditorium::cancelBooking(size_t r , size_t c ){
	tryLock();
	if(!checkBoundry(r, c)){
		unlock();
		return;
	}
	// std::cout << r << " " << c << std::endl;
	static_cast<Seat *>(fa->at( r , c ))->setState(SEAT_EMPTY);


	if(mementoLinked()){
		std::string buffer;
		std::stringstream ss;
		buffer.append("cancel ");
		buffer.append(fa->getValue(r , c )->getPerson()->toString());
		buffer.append(fa->getValue(r , c)->toString());
		buffer.append("Matrix{");
		ss << "Row:" << r << " Column:" << c << " Matrix}";
		buffer.append(ss.str());
		add_command(buffer);
	}
	fa->getValue(r , c )->bind(NULL);
	unlock();
}



bool FlexiAuditorium::findFree(size_t &r, size_t &c){
	for(size_t i = 0 ; i < fa->getRows() ; i++)
		for(size_t j = 0 ; j < fa->getColumns() ; j++)
			if(fa->getValue(i,j)->getState() == SEAT_EMPTY){
				r = i;
				c =j;
				return true;
			}
		return false;
}

bool FlexiAuditorium::checkBoundry( size_t r, size_t c){
	if( r > fa->getRows() )
		return false;
	if( c > fa->getColumns() )
		return false;
	if( fa->getValue(r,c)->getState() == SEAT_VOID )
		return false;
	return true;
}

bool FlexiAuditorium::setVoid(size_t r, size_t c, size_t s , bool vertical){		//Modify this function so it can set void in rows too.
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

void FlexiAuditorium::setState( size_t r, size_t c, short s){
	fa->getValue(r, c)->setState(s);
}

bool FlexiAuditorium::bookAdv(Group &group){
	size_t spaces = 0;
	size_t counter = 0;

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

			if(spaces == group.getSize()){
				spaceFound = true;
				break;
			}
		}
		if(spaceFound)
			break;
		spaces = 0;
	}

	if(spaceFound)
		for(size_t c = 0  ; c  < group.getSize() ; c++){
			book(group.at(counter++),i,j-c);
		}
	return spaceFound;
}
short FlexiAuditorium::getState( size_t row, size_t column){
	if(!checkBoundry(row, column))
		return SEAT_VOID;
	else
		return fa->getValue(row,column)->getState();
}


std::string FlexiAuditorium::dumpRaw(){
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

void FlexiAuditorium::dumpFile(std::string filename){
	std::ofstream fs(filename.c_str());
	fs << dumpRaw();
	fs.close();
}

Seat *FlexiAuditorium::getSeat( size_t row, size_t column){
		if(!checkBoundry(row, column))
			return NULL;
		else
			return fa->getValue(row, column);
}


Auditorium *FlexiAuditorium::clone(){
	FlexiAuditorium *newA = new FlexiAuditorium(fa->getRows(),fa->getColumns());
	for(size_t i = 0 ; i < fa->getRows() ; i++)
		for(size_t j = 0 ; j < fa->getColumns() ; j++)
			newA->fa->getValue( i , j )->setState(fa->getValue( i , j )->getState());
	newA->seats = seats;
	return newA;
}


void FlexiAuditorium::clear(){
	for(size_t i = 0 ; i < fa->getRows() ; i++)
		for(size_t j = 0 ; j < fa->getColumns() ; j++)
			if(fa->getValue( i , j )->getState() == SEAT_TAKEN)
				fa->getValue( i , j )->setState( SEAT_EMPTY );
}
