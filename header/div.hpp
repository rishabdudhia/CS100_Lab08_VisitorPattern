#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <iostream>
#include <string>
#include <iomanip>

 using namespace std;

 class Div : public Base {
    public:
        Div(Base* lhs, Base* rhs) : left(lhs), right(rhs) { }
       ~Div () {
		delete left;
		delete right;
	}
	 virtual double evaluate() { 
		double lhse = left->evaluate();
		double rhse = right->evaluate();
		if (rhse == 0)
			return 0;
		return (lhse/rhse); 
	}

        virtual string stringify() { 
		string rhss = right->stringify();
		string lhss = left->stringify();

	ostringstream ss;
        ss << setprecision(8) << noshowpoint << '(' << lhss << '/' << noshowpoint << rhss << ')';
	return  ss.str(); 
	}

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
			return v->visit_div_begin(this);
		else if (i == 1)
			return v->visit_div_middle(this);
		else
			return v->visit_div_end(this);
	}

    private: 
	Base* left;
	Base* right;
};

#endif
