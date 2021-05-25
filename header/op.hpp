#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iostream"
#include <sstream>
#include <iomanip>

using namespace std;

class Op : public Base {
    public:
        Op(double value) : Base(), val(value) { }	
        virtual double evaluate() { return val; }
	virtual std::string stringify() 
	    {
		ostringstream ss;
		ss << setprecision(8) << noshowpoint << val;
		return ss.str();
	    }

	int number_of_children() P
		return 0;
	}

	Base* get_child(int i) {
		return nullptr;
	}

	void check(Visitor* v, int i) {
		return v->visit_op(this);
	}
    private:
	double val;
};

#endif //__OP_HPP__
