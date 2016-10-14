/*!
 * Auditorium:
 * Abstract class which allows me to implement the three
 * other auditorium classes.
 */

#include "Auditorium.h"
Auditorium::~Auditorium(){
	if(memento)
		deleteMemento();
	if(printer)
		delete printer;
	if(strategy)
		delete strategy;
}

Auditorium::Auditorium(){
	printer = NULL;
	memento = NULL;
	guiMode = false;
	_mutex = false;
	strategy = NULL;
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
		createMemento();
	}
	else
		deleteMemento();
}

void Auditorium::createMemento(){
	if(!memento){
		memento = new AuditoriumMemento();
		memento->bind(this);
		return;
	}

	delete memento;
	createMemento();
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

bool Auditorium::ticketPrinterLinked(){
	return printer;
}

void Auditorium::enablePrinter(bool val){
	if(!val)
		return;
	if(printer)
		delete printer;
	printer = new TicketPrinter();
}
