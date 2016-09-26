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
#include "ListAsDynamicArray.h"
#include "FixedSizeMatrix.h"
#include "DynamicAuditorium.h"
#include "FixedAuditorium.h"
#include "Container.h"
#include "cColours.h"

using namespace std;

int main(){
      cout << GREEN "tickets - Connor Armand du Plooy u16169532 2016" RESET << endl;
      dynamicAuditorium da(25,25);

      da.setVoid(0,3,3,false);


      da.print(cout);
      std::cout << "_________________________________________________________________" << std::endl;
      char a;
      cin >> a;

      da.bookAdv(5);
      da.bookAdv(2);
      da.book(3,4);
      da.bookAdv(1);
      da.bookAdv(25);
      da.bookAdv(11);
            da.bookAdv(25);
                  da.bookAdv(25);
                        da.bookAdv(25);
                              da.bookAdv(25);
                                          da.bookAdv(2);
                                                      da.bookAdv(6);
      da.bookAdv(12);
      da.bookAdv(3);
      da.bookAdv(444);
      da.bookAdv(4);
      da.bookAdv(45);



      da.print(cout);
      return 0;
}
