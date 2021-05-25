#include "../header/factory.hpp"
#include <sstream>
#include <iostream>
#include <string>

Base* Factory::parse(char** input, int length) {
	int i = 1;
	Base* root = nullptr;
	stack<Base*> expressions;
	string curr = "";
	string next = "";

	while (i < length) {
		curr = (string)input[i];
		next = (string)input[i+1];

		if (valid_Op(curr)) { //checks if operand
			root = new Op(stod(curr));
		}
		else if (valid_Op(next) && curr == "+") {
			root = new Add(expressions.top(), new Op(stod(next)));
			++i;
		}
		else if (valid_Op(next) && curr == "-") {
			++i;
			root = new Sub(expressions.top(), new Op(stod(next)));
		}
		else if (valid_Op(next) && curr == "*") {
			++i;
			root = new Mult(expressions.top(), new Op(stod(next)));
		}
		else if (valid_Op(next) && curr == "/") {
			++i;
			root = new Div(expressions.top(), new Op(stod(next)));
		}
		else if (valid_Op(next) && curr == "**") {
			++i;
			root = new Pow(expressions.top(), new Op(stod(next)));
		}
		else {
			cout << "ERROR!" << endl;
			delete root;
			return nullptr;
		}

		expressions.push(root);
		++i;
	}

	return root;
}

bool Factory::valid_Op(const string& input) {
	stringstream in;
	in << input;
	double allowed;
	in >> allowed;
	return in.eof() && !in.fail();
}
