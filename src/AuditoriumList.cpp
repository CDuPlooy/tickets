#include "Auditorium.h"
#include "AuditoriumList.h"
//Unique functions
void AuditoriumList::push_back(Auditorium *auditorium){
	complex.push_back(auditorium);
}

void AuditoriumList::pop_back(){
	complex.pop_back();
}

Auditorium *AuditoriumList::at(size_t i){
	return (Auditorium *)complex.at(i);
}
