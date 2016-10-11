/**
 * \class AuditoriumModeller

 * \brief Models and constructs different kinds of auditoriums.

 */
#ifndef AUDITORIUM_MODELLER_H
#define AUDITORIUM_MODELLER_H
#include <string>
#include "Object.h"
#include "Auditorium.h"
#define AUD_FIXED 1
#define AUD_DYNAMIC 2
#define AUD_FLEXI 3
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
	/*! Loads an auditorium from a file.
	\param filename: A string representing the name of the file.
	\returns true/false if the auditorium was loaded correctly.
	*/
	bool loadFromFile(std::string filename);

	/*! Reduntant functiong ; Releases the internal auditorium pointer.
	*/
	void unbind();
	//Unique functions
	/*! Gets the internal auditorium pointer loaded by AuditoriumModeller::loadFromFile.
	\return An auditorium pointer.
	*/
	Auditorium *getAuditorium();

	/*! Constructs any kind of auditorium.
	\param type: AUD_FIXED , AUD_DYNAMIC , AUD_FLEXI ; Representing the kind of auditorium.
	\param x: The number of rows.
	\param y: The number of columns.
	\return An auditorium pointer.
	*/
	Auditorium *construct(short type,size_t x , size_t y);
	private:
	Auditorium *auditorium; /**! An internal auditorium instance returned by getAuditorium.*/
	bool  getRowSize(std::string filename , size_t &rows , size_t &columns ); /**! Parses a file to determine the auditorium size.*/
	};
	#endif
