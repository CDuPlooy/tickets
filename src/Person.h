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
      void setRow(size_t row);/**< Sets the row that the person booked a seat in.*/
      size_t getRow();/**< Returns the row that the person booked a seat in.*/
      void setColumn(size_t column); /**< Sets the column that the person booked a seat in.*/
      size_t getColunn();/**< Returns the column that the person booked a seat in.*/
      void setAge(unsigned short age);/**< Sets a person's age.*/
      float getFee();/**< Gets the fee that a person has to pay.*/
      void setFee(float fee); /**< Sets the fee that a person has to pay.*/
      std::string getName(){
          return name;
      }


      void setName(std::string name){
          this->name = name;
      }
private:
      std::string name;
      unsigned short age;
      size_t row;
      size_t column;
      float fee;
};
#endif

//Minor
//Adult
//Pensioner
//NullPerson
