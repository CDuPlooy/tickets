/**
 * \class AuditoriumMemento

 * \brief Aggregate of auditorium and it's subclasses , can undo any operation performed on auditorium.

 */
#ifndef SUMMARY_H
#define SUMMARY_H
#include "Object.h"
#include "Auditorium.h"

class Summary : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~Summary();
      Summary(Auditorium *aud);
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
private:
      Auditorium *aud;
};
#endif
