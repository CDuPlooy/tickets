//!  Super class which forms the root of all other classes

#include <iostream>
#ifndef OBJECT_H
#define OBJECT_H
class Object{
protected:
      virtual int compareTo(Object const &) const = 0;
public:
      Object(){};
      virtual ~Object(){};

	/*! Determines whether an object is an instance of NullObject.
	\return true/false if object is of type of NULL.
	*/
      virtual bool isNull(void) const = 0 ;

	/*! Compares two objects.
	\param obj: The object to compare to the caller.
	\return true/false if equal/not.
	*/
      virtual int compare(Object const &obj) const = 0;

	/*! Outputs the object.
	\param out: The stream to output to ( default is std::cout  ) .
	*/
      virtual void print(std::ostream &out = std::cout) const = 0;

	/*! A string representation of the object type.
	\return  A std::string representing the object type.
	*/
      virtual std::string getId() const = 0;
private:
};
#endif
