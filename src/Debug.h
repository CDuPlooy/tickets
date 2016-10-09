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
	void debug_addr(std::string msg , void *addr){
		if(!supOut)
			std::cout << __FILE__ << ": Address : " << addr  << " [ " << msg << " ]" <<std::endl;
	}
	void debug_message(std::string msg){
		if(!supOut)
			std::cout << __FILE__ << ':' << __LINE__ << " RET @ " << __builtin_return_address(0) << " [ " << msg << " ]" <<std::endl;
	}
	void assert(bool expression , std::string msg , bool critical){
		if(!expression){
			debug_message(msg);

			if(critical){
				exit(1);
			}
		}
}

	void setSuppression(bool value){
		supOut  = value;
	}
private:
	bool supOut;
};
#endif
