//!  The integer class is used for debugging and testing.
#ifndef INTEGER_H
#define INTEGER_H
#include "Object.h"
class Integer : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      Integer();
      Integer(int a);
      ~Integer(){};
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Overloaded Operators
      Integer operator=(int a);
      bool operator==(Integer &i);
      bool operator<=(Integer &i);
      bool operator>=(Integer &i);
      bool operator!=(Integer &i);
      bool operator==(int i);
      bool operator<=(int i);
      bool operator>=(int i);
      bool operator!=(int i);

private:
      int _internal;
};

#endif
