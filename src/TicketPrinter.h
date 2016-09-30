//!  Prints tickets for auditoriums.
#ifndef TICKETPRINTER_H
#define TICKETPRINTER_H
#include "Object.h"
#include "Auditorium.h"
class TicketPrinter : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~TicketPrinter();
      TicketPrinter( Auditorium *auditorium );
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
private:
      Auditorium *auditorium;
};
#endif
