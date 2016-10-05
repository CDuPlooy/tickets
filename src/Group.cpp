#include "Group.h"
Group::Group(){

}

Group::~Group(){

}

void Group::push_back(Person *person){
	_group.push_back(person);
}

void Group::pop_back(){
	_group.pop_back();
}

Person *Group::at(size_t i){
	return _group.at(i);
}

size_t Group::getSize(){
	return _group.size();
}
