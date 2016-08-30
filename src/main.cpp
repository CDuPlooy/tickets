/*
Connor Armand Du Plooy
u16169532
*/
#include <iostream>
#include "Object.h"
#include "NullObject.h"
#include "Integer.h"

#include "List.h"
#include "ListAsVector.h"

using namespace std;

int main(){
      NullObject a;

      Integer b = 3;



      ListAsVector c;
      c.push_back(&a);
      c.push_back(&b);
      c.push_back(&c);

      c.print(std::cout);
      c.at(0)->print();
      c.at(1)->print();
      c.at(2)->print();

      return 0;
}
