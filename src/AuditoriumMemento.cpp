#include<cstdlib>
#include "AuditoriumMemento.h"
#include "Auditorium.h"
#include "Seat.h"
#include "Minor.h"
#include "Adult.h"
#include "Pensioner.h"
#include "Person.h"
#include "Debug.h"

int AuditoriumMemento::compareTo(Object const &) const{
	return 1;
}


//Constructors
AuditoriumMemento::~AuditoriumMemento(){

}

AuditoriumMemento::AuditoriumMemento(){
	auditorium = NULL;
}

//Overloaded Functions
bool AuditoriumMemento::isNull(void) const{
	return false;
}

int AuditoriumMemento::compare(Object const &) const{
	return 1;
}

void AuditoriumMemento::print(std::ostream &out) const{
	out << "Auditorium Memento Commands : " << std::endl;
	for(size_t i = 0 ; i < commands.size() ; i++)
		out <<  i+1  << ".) "<< commands.at(i) << std::endl;
}

std::string AuditoriumMemento::getId() const{
	return  "AuditoriumMemento";
}

void AuditoriumMemento::bind(Auditorium *auditorium){
	this->auditorium = auditorium;
}

void AuditoriumMemento::add_command(std::string command){
	commands.push_back(command);
}
void AuditoriumMemento::undo(){
	if(commands.size() == 0)
		return;
	std::string command = commands.at(commands.size()-1);
	commands.pop_back();
	exec(command);
}

void AuditoriumMemento::exec(std::string command){
	//TODO: Implement the interpreter.
	//Person{Name:Kathy Age:0 Fee:21.5}Seat{State:0}Matrix{row:0 column:0}
	//If command == book
	//	cancelBooking
	std::string com("");
	size_t i = 0;
	for( ; i < command.size() ; i++)
		if(command[i] == ' ')
			break;
		else
		com.push_back(command[i]);

	std::string personRaw = extract( command , "Person{","Person}");
	std::string Type = extract( personRaw , "Type:"," ");
	size_t age = atoi(extract(personRaw , "Age:"," ").c_str());
	double fee = atof(extract(personRaw , "Fee:"," ").c_str());
	Person *person;
	if(Type == "Minor"){
		person = new Minor();
	}
	else if(Type == "Adult"){
		person = new Adult();
	}
	else
		person = new Pensioner();
	person->setAge(age);
	person->setFee(fee);

	std::string seatRaw = extract( command , "Seat{","Seat}");
	size_t state = atoi(extract( seatRaw , "Seat{","Seat}").c_str());
	Seat *seat = new Seat(person);
	seat->setState(state);

	std::string matrixRaw = extract(command  , "Matrix{","Matrix}");
	size_t x = atoi(extract(matrixRaw,"row:"," ").c_str());
	size_t y = atoi(extract(matrixRaw,"column:"," ").c_str());

	if(com == "book"){
		auditorium->cancelBooking(x,y);
	}
	else if(com == "cancel"){
		auditorium->book(person, x, y);
	}
}

std::string AuditoriumMemento::extract(std::string buffer , std::string begin , std::string end){
		std::string retbuffer;
		size_t startPos = buffer.find(begin);
		if( startPos == -1)
			return "";

		size_t endPos = buffer.find(end);
		if(endPos == -1)
			return "";
		startPos+=begin.length();
		for(size_t i = startPos ; i < endPos ; i++)
			retbuffer.push_back(buffer[i]);
		return retbuffer;
}
