#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "iostream"
#include <sstream>
#include <iomanip>

using namespace std;

class Sub : public Base {
    public:
        Sub (Base* left, Base* right) : Base(), left(left), right(right) { }
        ~Sub () {
		delete left;
		delete right;
	}
	virtual double evaluate() {return left->evaluate() - right->evaluate(); }
        virtual std::string stringify()
            {
                ostringstream ss;
                ss << setprecision(8) << noshowpoint << '(' << left->stringify() << '-' << noshowpoint << right->stringify() << ')';
                return ss.str();
            }
    private:
        Base* left;
        Base* right;
};

#endif //__SUB_HPP__

