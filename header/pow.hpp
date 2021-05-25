#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "iostream"
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

class Pow : public Base {
    public:
        Pow (Base* left, Base* right) : Base(), left(left), right(right) { }
        ~Pow () {
		delete left;
		delete right;
	}
	virtual double evaluate() {return (pow(left->evaluate(),right->evaluate())); }
        virtual std::string stringify()
            {
                ostringstream ss;
                ss << setprecision(8) << noshowpoint << '(' << left->stringify() << "**" << noshowpoint << right->stringify() << ')';
                return ss.str();
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
			return v->visit_pow_begin(this);
		else if (i == 1)
			return v->visit_pow_middle(this);
		else
			return v->visit_pow_end(this);
	}
    private:
        Base* left;
        Base* right;
};

#endif //__POW_HPP__

