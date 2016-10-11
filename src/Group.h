//!  Models a group of people such  as a familty.
/*!
      Binds People to a ListAsVector implementation.
*/
#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include "Object.h"
#include "Person.h"
class Group{
public:
	Group();
	~Group();

	/*! Adds a person to the goup.
	\param person: A person pointer.
	*/
	void push_back(Person *person);

	/*! Removes a person from the goup.
	*/
	void pop_back();

	/*! Returns the person at i.
	\param i: A size_t representing the position in the vector.
	\return A person instance.
	*/
	Person *at(size_t i);

	/*! Returns the size of the group.
	\return The size of the group.
	*/
	size_t getSize();
private:
	std::vector<Person *> _group;
};
#endif
