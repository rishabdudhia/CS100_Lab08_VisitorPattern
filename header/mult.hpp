#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"
#include <iostream>
#include <string>
#include <iomanip>

 using namespace std;

 class Mult : public Base {
    public:
        Mult(Base* lhs, Base* rhs) : left(lhs), right(rhs) { }
        ~Mult () {
		delete left;
		delete right;
	}
	virtual double evaluate() { 
		double lhse = left->evaluate();
		double rhse = right->evaluate();
	return (rhse*lhse); }

        virtual string stringify() { 
		string rhss = right->stringify();
		string lhss = left->stringify();

	ostringstream ss;
        ss << setprecision(8) << noshowpoint << '(' << lhss << '*' << noshowpoint << rhss << ')';
	return  ss.str(); }

    private: 
	Base* left;
	Base* right;
};

#endif
