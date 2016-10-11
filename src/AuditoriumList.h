//!  Can model complexes.
/*!
      Creates groups of auditoriums.
*/
#ifndef AUDITORIUM_LIST_H
#define AUDITORIUM_LIST_H
#include "Object.h"
#include "ListAsVector.h"
class AuditoriumList {
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~AuditoriumList();
      AuditoriumList();

	/*! Adds an auditorium to the list.
	\param auditorium: An auditorium pointer..
	*/
      void push_back(Auditorium *auditorium);

	/*! Removes an auditorium from the list.
	*/
      void pop_back();

	/*! Returns the auditorium at positition at i.
	\param i: size_t representing position in the vector.
	\return An auditorium instance.
	*/
      Auditorium *at(size_t i);

	/*! Returns the size of the list.
		\return Thee size of the list.
	*/
      size_t getSize();
private:
      ListAsVector complex;
};
#endif
