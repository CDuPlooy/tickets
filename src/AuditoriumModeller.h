//!  Can model auditoriums.
/*!
      Creates auditoriums from text files.
*/
#ifndef AUDITORIUM_MODELLER_H
#define AUDITORIUM_MODELLER_H
#include <string>
#include "Object.h"
#include "Auditorium.h"
class AuditoriumModeller : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      AuditoriumModeller(); /**< AuditoriumModeller Constructor. */
      ~AuditoriumModeller(); /**< AuditoriumModeller Destructor.*/

      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;/**< */
      void print(std::ostream & = std::cout) const;/**< */
      std::string getId() const;/**< */
      //Unique Functions
      bool loadFromFile(std::string);/**< Loads an auditorium from a text file.*/
      void unbind(); /**< Releases the Auditorium pointer bound to the private member auditorium by setting it to NULL */
      //Unique functions
      Auditorium *getAuditorium();/**< Returns an auditorium instance. Please note that this function depends on loadFromFile.*/


private:
      Auditorium *auditorium; /**! An internal auditorium instance returned by getAuditorium.*/
      bool  getRowSize(std::string filename , size_t &rows , size_t &columns ); /**! Parses a file to determine the auditorium size.*/
};
#endif
