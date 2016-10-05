#ifndef AUDITORIUM_MEMENTO_H
#define AUDITORIUM_MEMENTO_H
#include "Object.h"
class Auditorium;	// Makes an empty promise to the compiler.
class AuditoriumMemento : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~AuditoriumMemento();
      AuditoriumMemento();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
	void bind(Auditorium *auditorium); /**< When a memento is constructed it will be bound to an auditorium and the auditorium bound to it.*/
private:
	Auditorium *auditorium;
};
#endif
