/**
 * \class Store

 * \brief Stores and iterates over list objects.

 */
#ifndef STORE_H
#define STORE_H
#include "Object.h"
#include "Container.h"
//Defines
#define CSLL 0
#define CDLL 1
#define CVECTOR 2
#define CDYNARR 3
//Classes
class Store : public Object{
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~Store();
      Store( short choice );
      //Overloaded Functions
      bool isNull(void) const;
      int compare(Object const &) const;
      void print(std::ostream & = std::cout) const;
      std::string getId() const;
      //Unique Functions
      //Iterator Functions

	/*! Gets the current object / cursor
	\return An object pointer or a cursror.
	*/
	Object *getCurrent();

	/*! Moves the cursor to the next object.
	*/
      void next();

	/*! Moves the cursor to the previous object.
	*/
      void previous();

	/*! Adds an object to the data structure.
	\param object: A pointer to an Object.
	*/
      void push_back(Object *obj);

	/*! Removes an object * from the top of the data structure.
	*/
      void pop_back();

	/*! Determines whether the cursor is at the end of the data structure.
	\return Returns true when the cursor is at the end of the data structure.
	*/
      bool isAtEnd();



private:
      Container *container;
};
#endif
