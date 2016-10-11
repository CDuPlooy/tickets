/**
 * \class Debug

 * \brief A class used simply for debugging.

 */
#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#include <cstdlib>
class Debug{
public:
	Debug(){
		supOut = false;
	}
	~Debug(){

	}

	/*! Debug message with address.
	\param msg: The message to display.
	\param addr: The address to display.
	*/
	void debug_addr(std::string msg , void *addr){
		if(!supOut)
			std::cout << __FILE__ << ": Address : " << addr  << " [ " << msg << " ]" <<std::endl;
	}

	/*! Debug message , using the preprocessor to print function addresses.
	\param msg: The message to display.
	*/
	void debug_message(std::string msg){
		if(!supOut)
			std::cout << __FILE__ << ':' << __LINE__ << " RET @ " << __builtin_return_address(0) << " [ " << msg << " ]" <<std::endl;
	}

	/*! Assertion and a  message.
	\param expression: The assertion expression.
	\param msg: The message to be printed.
	\param ciritical: Exit process if true.

	*/
	void assert(bool expression , std::string msg , bool critical){
		if(!expression){
			debug_message(msg);

			if(critical){
				exit(1);
			}
		}
}

/*! Enables supression of debug output.
\param value: true/false to enable/disable.
*/
	void setSuppression(bool value){
		supOut  = value;
	}
private:
	bool supOut;
};
#endif
