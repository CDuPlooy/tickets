/*!
 * Auditorium:
 * Abstract class which allows me to implement the three
 * other auditorium classes.
 */

#include "Auditorium.h"
Auditorium::~Auditorium(){
	if(memento)
		deleteMemento();
}

Auditorium::Auditorium(){
	memento = NULL;
}

//Overloaded Functions
bool Auditorium::isNull(void) const{
	return 1; //Marker:Unsure
}

int Auditorium::compare(Object const &) const{
	return 1; //Marker:Unsure
}

void Auditorium::print(std::ostream &out) const{
	out << "Marker:Unsure";
}

std::string Auditorium::getId() const{
	return "Auditorium";
}

int Auditorium::compareTo(Object const &) const{
	return 1; //Marker:Unsure
}

void Auditorium::setState( size_t , size_t , short ){
	return; //empty declaration
}

void Auditorium::enableMemento(bool value){
	if(value){
		deleteMemento();
		createMemento();
	}
	else
		deleteMemento();
}

void Auditorium::createMemento(){
	memento = new AuditoriumMemento();
	memento->bind(this);
}
bool Auditorium::mementoLinked(){
	return memento;
}

void Auditorium::deleteMemento(){
	if(memento)
		delete memento;
}

AuditoriumMemento *Auditorium::getMemento(){
	return memento;
}



void Auditorium::add_command(std::string command){
	if(!memento)
		return;
	memento->add_command(command);
}

void Auditorium::undo(){
	if(!memento)
		return;
	memento->undo();
}
