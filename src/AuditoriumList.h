#ifndef AUDITORIUM_LIST_H
#define AUDITORIUM_LIST_H
#include "Object.h"
#include "ListAsVector.h"
class AuditoriumList {
protected:
      int compareTo(Object const &) const;
public:
      //Constructors
      ~AuditoriumList();
      AuditoriumList();

      void push_back(Auditorium *auditorium);/**< Adds an auditorium to the complex.*/
      void pop_back();/**< Removes an auditorium from the complex.*/
      Auditorium *at(size_t i);/**< Returns the auditorium at i.*/
      size_t getSize();
private:
      ListAsVector complex;
};
#endif
