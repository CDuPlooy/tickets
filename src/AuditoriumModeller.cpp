#include <fstream>
#include "AuditoriumModeller.h"
#include "Auditorium.h"
#include "FixedAuditorium.h"
#include "DynamicAuditorium.h"

AuditoriumModeller::AuditoriumModeller(){
	auditorium = NULL;
}

AuditoriumModeller::~AuditoriumModeller(){

}

//Overloaded Functions
bool AuditoriumModeller::isNull(void) const{
	return false;
}

int AuditoriumModeller::compare(Object const &) const{
	return false; //Marker:Unsure
}

void AuditoriumModeller::print(std::ostream &out) const{
	out << "Auditorium Modeller";
}

std::string AuditoriumModeller::getId() const{
	return "AuditoriumModeller";
}

bool AuditoriumModeller::loadFromFile(std::string filename){
	std::fstream fs(filename.c_str());
	std::string buffer;
	size_t lines = 0;

	while( !fs.eof() ){
		fs >> buffer;
		lines++;
	}
	fs.close();

	if(auditorium)
		delete auditorium; //Marker:Unsure	Free the pointer if it's already been allocated.

	if( buffer.find("   ") )
		auditorium = new dynamicAuditorium( lines , lines );
	else
		auditorium = new fixedAuditorium( lines , lines );

	size_t rows = 0 , columns = 0;
	for( size_t i = 0 ; i < buffer.size() ;  i++ ){
		if( buffer.at(i) == 'X' )
			auditorium->setState( rows , columns , SEAT_TAKEN);
		else
			auditorium->setState( rows , columns , SEAT_VOID);

		rows++;
		if(rows > lines){
			rows = 0;
			columns++;
		}

	}
	return true;

}

Auditorium *AuditoriumModeller::getAuditorium(){
	return auditorium;
}


int AuditoriumModeller::compareTo(Object const &) const{
	return 1; //Marker:Unsure
}
