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
	void push_back(Person *person);/**< Adds a person to the group.*/
	void pop_back();/**< Removes a person from the group.*/
	Person *at(size_t i);/**Returns a person at position i inside the group.*/
	size_t getSize();/**< Returns the size of the group.*/
private:
	std::vector<Person *> _group;
};
#endif
