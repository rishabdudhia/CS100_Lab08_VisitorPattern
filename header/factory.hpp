#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "add.hpp"
#include "base.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "sub.hpp"

#include <stack>
#include <cctype>
#include <string>

using namespace std;

class Factory {
 private:
	bool valid_Op(const string& input);
    public:
	Factory() {}
	Base* parse (char** input, int length); 
};

#endif
