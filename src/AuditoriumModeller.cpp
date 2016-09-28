#include <fstream>
#include "AuditoriumModeller.h"
#include "Auditorium.h"
#include "FixedAuditorium.h"
#include "DynamicAuditorium.h"
#include "Seats.h"

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
	if(!fs.is_open())
		return false;

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

	std::string line;
	size_t rows = 0, columns = 0;
	for(size_t i = 0 ; i < buffer.size() ; i++){
		if(buffer.at(i) != '\n')
			line.push_back(buffer.at(i));
		else{ //We now have a complete line , parse it and start constructing
			for(size_t j = 1 ; j < line.length() ; j++){
				//Parse the string

				if( line.at(j) == 'X' )
					auditorium->setState(rows++,columns,SEAT_TAKEN);
				if( line.at(j) == '0' )
					auditorium->setState(rows++,columns,SEAT_EMPTY);
			}
			std::cout << ">>" << line << "<<";
			columns++;
			line.clear();
			line = "";
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
