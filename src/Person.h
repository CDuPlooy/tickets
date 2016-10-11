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

	/*! Sets the rows.
	\param row: The number of rows.
	*/
      void setRow(size_t row);

	/*! Gets the number of rows.
	\return The number of rows.
	*/
      size_t getRow();

	/*! Sets the column.
	\param column: The number of columns.
	*/
      void setColumn(size_t column);

	/*! Gets the number of columns.
	\return The number of columns.
	*/
      size_t getColunn();

	/*! Sets the age of the person.
	\param age: The age to set to.
	*/
      void setAge(unsigned short age);

	/*! Gets the age of the person.
	\return The age of the person.
	*/
	unsigned short getAge(){
		return age;
	}

	/*! Gets the fee of the person.
	\return The fee of the person.
	*/
      float getFee();

	/*! Sets the fee of the person.
	\param fee: The fee to set to.
	*/
      void setFee(float fee);

	/*! Gets the name of the person.
	\return The name of the person.
	*/
      std::string getName(){
          return name;
      }
	/*! Sets the name of the person.
	\param name: The name to set to.
	*/
      void setName(std::string name){
          this->name = name;
      }

	/*! Sums up the person class as a string
	\return A string representation of Person.
	*/
	virtual std::string toString() = 0;

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
