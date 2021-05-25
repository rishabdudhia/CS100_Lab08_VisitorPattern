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

	int number_of_children() {
		return 2;
	}
	Base* get_child(int i){
		if (i == 0)
			return left;
		else if (i == 1)
			return right;
		else
			return nullptr;
	}
	void check(Visitor* v, int i){
		if (i == 0)
			return v->visit_mult_begin(this);
		else if (i == 1)
			return v->visit_mult_middle(this);
		else
			return v->visit_mult_end(this);
	}
    private: 
	Base* left;
	Base* right;
};

#endif
