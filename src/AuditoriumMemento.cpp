#include "AuditoriumMemento.h"
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
}
