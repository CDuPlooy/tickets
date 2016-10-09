//!  Prints tickets for auditoriums.
#ifndef TICKETPRINTER_H
#define TICKETPRINTER_H
#include "Object.h"
#include "Seat.h"
class TicketPrinter : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~TicketPrinter();
      TicketPrinter();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
      void printSeat(Seat *seat , bool printRaw);
      // std::string printAuditorium(Auditorium *auditorium , size_t x , size_t y , bool printRaw);
};
#endif
