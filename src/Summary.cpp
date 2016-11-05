/**
 * \class AuditoriumMemento

 * \brief Aggregate of auditorium and it's subclasses , can undo any operation performed on auditorium.

 */
#include <string>
#include "Summary.h"
#include "cColours.h"
      int Summary:: compareTo(Object const &) const{
            return 1;
      }


      Summary::~Summary(){

      }

      Summary::Summary(Auditorium *aud){
            this->aud = aud;
      }


      bool Summary:: isNull(void) const{
            return false;
      }

      int Summary::compare(Object const &) const{
            return -1;
      }

      void Summary::print(std::ostream &os) const{
            double totalFee = 0;
            size_t totalSeats = 0;
            size_t emptySeats = 0;
            size_t takenSeats = 0;
            for(size_t i = 0 ; i < aud->rows ; i++)		//Marker:SpecialCase ---> Coloured output might not work for a text box
                  for(size_t j = 0 ; j < aud->columns ; j++){
                  if(aud->getSeat(i,j)->getState() == SEAT_TAKEN){
                        totalFee += aud->getSeat(i,j)->getPerson()->getFee();
                        takenSeats++;
                  }
                  else if( aud->getSeat(i,j)->getState() == SEAT_EMPTY )
                        emptySeats++;

                  }
                  totalSeats = emptySeats + takenSeats;
                  os << RED << aud->getName() << RESET << std::endl;
                  os << "Total Seats : " GREEN << totalSeats << RESET << std::endl;
                  os << "Taken Seats : " << GREEN << takenSeats << RESET << std::endl;
                  os << "Empty Seats: " << GREEN << emptySeats << RESET << std::endl;
                  os <<  "Total Income: R" << BLUE << totalFee << RESET << std::endl;

      }

      std::string Summary::getId() const{
            return "Summary";
      }
