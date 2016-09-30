//!  A class representing a person.
/*!
      For the purpose of this assignment
      unsigned shorts are used to represent
      state.
*/
#ifndef PERSON_H
#define PERSON_H
#include "Object.h"
class Person : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~Person();
      Person();
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
      void setRow(size_t row);
      size_t getRow();
      void setColumn(size_t column);
      size_t getColunn();
      void setAge(unsigned short age);

private:
      std::string name;
      unsigned short age;
      size_t row;
      size_t column;
};
#endif

//Minor
//Adult
//Pensioner
//NullPerson
