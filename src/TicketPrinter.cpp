//!  A class which is used to print tickets
#include <sstream>
#include "cColours.h"
#include "Debug.h"
#include "TicketPrinter.h"
int TicketPrinter::compareTo(Object const &) const{
	return false;
}

TicketPrinter::~TicketPrinter(){

}

TicketPrinter::TicketPrinter(){

}

bool TicketPrinter::isNull(void) const{
	return false;
}

int TicketPrinter::compare(Object const &) const{
	return 1;
}

void TicketPrinter::print(std::ostream &out) const{

}

std::string TicketPrinter::getId() const{
	return "TicketPrinter";
}

std::string TicketPrinter::printSeat(Seat *seat , bool printRaw){
	std::stringstream buffer("");
	buffer.clear();
	if(!seat->getPerson())
		return "";
	if(printRaw){
		buffer << "Name: \t" << seat->getPerson()->getName() <<  "\n";
		buffer << "Price: \tR" << seat->getPerson()->getFee() << "\n";
	}
	else{
		buffer << "Name: \t" RED << seat->getPerson()->getName() << RESET "\n";
		buffer << "Price: " RED  << "\tR" << seat->getPerson()->getFee() << RESET "\n";
	}
	return  buffer.str();
}

std::string TicketPrinter::printAuditorium(Auditorium *auditorium , size_t x , size_t y , bool printRaw){
	if (auditorium->getState(x, y) == SEAT_VOID)
		return "";
	std::stringstream buffer("");
	if(printRaw){
		buffer << auditorium->getName() << " Ticket\n";
		buffer << printSeat(auditorium->getSeat(x,y), printRaw);
	}
	else{
		buffer << RED << auditorium->getName() << RESET << " Ticket\n";
		buffer << printSeat(auditorium->getSeat(x,y), printRaw);
	}
	return buffer.str();
}
