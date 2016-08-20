#include <iostream>
#include "Object.h"

void NullObject::print(std::ostream& os) const{

}

NullObject::NullObject(){
      
}

bool NullObject::isNull(void) const{
      return true;
}
