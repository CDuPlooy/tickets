#ifndef DEBUG_H
#define DEBUG_H
#include "assert.h"
#define D_MSG(MSG) std::cout << __FILE__ << ":" << __LINE__ << "\t[ " << MSG << " ]" << std::endl;
#endif
