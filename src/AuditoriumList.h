#ifndef AUDITORIUM_DEVELOPER_H
#define AUDITORIUM_DEVELOPER_H
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
private:
      ListAsVector complex;

};
#endif
