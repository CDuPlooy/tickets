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
	/*! Sets internal int to.
	\param a: An int to set the internal int to.
	*/
      Integer operator=(int a);

	/*! Compares integers.
	\param a: An int to set the internal int to.
	\return true/false;
	*/
      bool operator==(Integer &i);

	/*! Compares integers.
	\param i: An int to set the internal int to.
	\return true/false;
	*/
      bool operator<=(Integer &i);

	/*! Compares integers.
	\param i: An int to set the internal int to.
	\return true/false;
	*/
      bool operator>=(Integer &i);

	/*! Compares integers.
	\param i: An int to set the internal int to.
	\return true/false;
	*/
      bool operator!=(Integer &i);

	/*! Compares integers.
	\param i: An int to set the internal int to.
	\return true/false;
	*/
      bool operator==(int i);

	/*! Compares integers.
	\param i: An int to set the internal int to.
	\return true/false;
	*/
      bool operator<=(int i);

	/*! Compares integers.
	\param i: An int to set the internal int to.
	\return true/false;
	*/
      bool operator>=(int i);

	/*! Compares integers.
	\param i: An int to set the internal int to.
	\return true/false;
	*/
      bool operator!=(int i);


private:
      int _internal;
};

#endif
