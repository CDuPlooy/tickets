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
#include "Matrix.h"
#include "Container.h"

using namespace std;

int main(){

      FixedSizeMatrix fs(0);
      fs.add((Object *)&fs);

      return 0;
}
