//!  An abstract class.
/*!
  Allows for the definition of multiple strategies to book an auditorium.
*/
#include "Auditorium.h"
#include "Object.h"
#ifndef BOOKING_H
#define BOOKING_H
#define BOOK_BEST_VIEW 1
#define BOOK_BEST_FIT 2
#define BOOK_FAMILY 3
class Booking : public Object{
public:
	/*! Associates an auditorium with a booking.
    \param aud: The auditorium pointer to associate booking with.
	*/
	void setAuditorium(Auditorium *aud){
		auditorium = aud;
	}

	/*! Returns an auditorium associated with a booking.
    \return The auditorium pointer  associated with booking.
	*/
	Auditorium *getAuditorium(){
		return auditorium;
	}

	/*! Determines whether a booking for a particular strategy could be made.
    \return true/false if booking could be made or not.
	*/
	// virtual bool canBook() = 0;
	//
	// /*! Calls the auditorium class to make bookings.
	// */
	// virtual void book() = 0;

	//Inheritance issues
	~Booking(){

	};
	Booking(){

	};
	//Overloaded Functions
	bool isNull(void) const{
		return false;
	};
	int compare(Object const &) const{
		return 1;
	}
	void print(std::ostream &out = std::cout) const{
		out << "Booking";
	}
	std::string getId() const{
		return "Booking";
	}
protected:
	int compareTo(Object const &) const{
		return 1;
	}
private:
	Auditorium *auditorium;
};
#endif
