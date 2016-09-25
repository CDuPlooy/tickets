/*
Connor Armand Du Plooy
u16169532
*/
#include <iostream>
#ifndef OBJECT_H
#define OBJECT_H
class Object{
protected:
      virtual int compareTo(Object const &) const = 0;
public:
      Object(){};
      virtual ~Object(){};
      virtual bool isNull(void) const = 0 ;
      virtual int compare(Object const &) const = 0;
      virtual void print(std::ostream & = std::cout) const = 0;
      virtual std::string getId() const = 0;
private:
};
#endif
