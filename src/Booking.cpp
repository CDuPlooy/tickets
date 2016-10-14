#include "Booking.h"
#include "Group.h"

bool Booking::canBook(Group *group){
	if( strategyType == BOOK_BEST_VIEW ){ //Prioritize seats at the back
		size_t spaces = 0;
		size_t counter = 0;

		bool spaceFound = false;
		size_t j;
		size_t i;

		for( i = 0 ; i < auditorium->rows ; i++){
			for(j = 0 ; j < auditorium->columns/2 ; j++){
				if( auditorium->getState(i, j) == SEAT_EMPTY ){
					spaces++;
				}
				else{
					spaces = 0;
					continue;
				}

				if(spaces == group->getSize()){
					spaceFound = true;
					break;
				}
			}
			if(spaceFound)
				break;
			spaces = 0;
		}

		if(spaceFound)
			for(size_t c = 0  ; c  < group->getSize() ; c++){
				auditorium->book(group->at(counter++),i,j-c);
			}
		return spaceFound;
	}
	else if( strategyType == BOOK_BEST_FIT || strategyType == BOOK_FAMILY ){
		size_t spaces = 0;
		size_t counter = 0;

		bool spaceFound = false;
		size_t j;
		size_t i;

		for( i = 0 ; i < auditorium->rows ; i++){
			for(j = 0 ; j < auditorium->columns ; j++){
				if( auditorium->getState(i, j) == SEAT_EMPTY ){
					spaces++;
				}
				else{
					spaces = 0;
					continue;
				}

				if(spaces == group->getSize()){
					spaceFound = true;
					break;
				}
			}
			if(spaceFound)
				break;
			spaces = 0;
		}

		if(spaceFound)
			for(size_t c = 0  ; c  < group->getSize() ; c++){
				auditorium->book(group->at(counter++),i,j-c);
			}
		return spaceFound;
	}
	else if ( strategyType == BOOK_BAD_SIGHT ){
		size_t spaces = 0;
		size_t counter = 0;

		bool spaceFound = false;
		size_t j;
		size_t i;

		for( i = auditorium->rows/2; i < auditorium->rows ; i++){
			for( j =  0 ; j < auditorium->columns ; j++){
				if( auditorium->getState(i, j) == SEAT_EMPTY ){
					spaces++;
				}
				else{
					spaces = 0;
					continue;
				}

				if(spaces == group->getSize()){
					spaceFound = true;
					break;
				}
			}
			if(spaceFound)
				break;
			spaces = 0;
		}

		if(spaceFound)
			for(size_t c = 0  ; c  < group->getSize() ; c++){
				auditorium->book(group->at(counter++),i,j-c);
			}
		return spaceFound;
	}

	return true;
}
