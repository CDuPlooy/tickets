#ifndef FIXEDAUDITORIUM_H
#define FIXEDAUDITORIUM_H
#include "Object.h"
#include "Auditorium.h"
class fixedAuditorium : public Auditorium{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~fixedAuditorium();
      fixedAuditorium(size_t size);
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
private:
      size_t _size;
};
#endif
