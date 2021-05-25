#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "iostream"
#include "base.hpp"
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Rand : public Base{
	public:
		Rand() : Base(){
			srand(time(0));
			randvalue = rand()%100;
			 }
		virtual double evaluate() { return randvalue; }
		virtual string stringify() {
			ostringstream ss;
			ss << setprecision(8) << noshowpoint << randvalue;
		}
	private:
		double randvalue;
};

#endif //__RAND_HPP_
