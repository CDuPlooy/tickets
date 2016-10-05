#ifndef DEBUG_H
#define DEBUG_H
#include "assert.h"
#define D_MSG(MSG) std::cout << __FILE__ << ":" << __LINE__ << "\t[ " << MSG << " ]" << std::endl; /**< Prints a message and then continues execution. */
#define D_PAUSE(MSG)  std::cout << __FILE__ << ":" << __LINE__ << "\t[ " << MSG << " ]" << std::endl; char abcd;std::cin>>abcd; /**< Prints a message and pauses execution.*/
#endif
