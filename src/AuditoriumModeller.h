#ifndef AUDITORIUM_MODELLER_H
#define AUDITORIUM_MODELLER_H
#include <string>
#include "Object.h"
#include "Auditorium.h"
class AuditoriumModeller : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      AuditoriumModeller();
      ~AuditoriumModeller();

      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
      bool loadFromFile(std::string);


      //Unique functions
      Auditorium *getAuditorium();
private:
      Auditorium *auditorium;
};
#endif
