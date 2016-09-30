#include "TicketPrinter.h"
int TicketPrinter::compareTo(Object const &) const{
	return false;
}

TicketPrinter::~TicketPrinter(){

}

TicketPrinter::TicketPrinter(Auditorium *auditorium){
	this->auditorium = auditorium;
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
