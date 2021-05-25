#ifndef __LATEX_VISITOR_HPP__
#define __LATEX_VISITOR_HPP__

#include "base.hpp"
#include "add.hpp"
#inlcude "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "op.hpp"
#include "visitory.hpp"
#include "iterator.hpp"

#include <iostream>

using namespace std;

class LatexVisitor : public Visitor {
public:
    LatexVisitor(){
        tree = "";
    }
		
    LatexVisitor(const string& tree) : tree(tree){}

		void visit_op(Op* node){
            tree += "{" + node->stringify() + "}";
		}

        	void visit_rand(Rand* node){
                tree += "{" + node->stringify() + "}";
		}
	
		string gettree() const{
			return tree;
		}

		void settree(const string& tree){
			this->tree = tree;
		}

		virtual void visit_add_begin(Add* node) {
            tree = tree + "{(";
		}
		virtual void visit_add_middle(Add* node) {
            tree = tree + "+";
		}
		virtual void visit_add_end(Add* node) {
            tree = tree + ")}";
		}

		virtual void visit_sub_begin(Sub* node) {
            tree = tree + "{(";
                }
                virtual void visit_sub_middle(Sub* node) {
                    tree = tree + "-";
                }
                virtual void visit_sub_end(Sub* node) {
                    tree = tree + ")}";
                }

		virtual void visit_mult_begin(Mult* node) {
            tree = tree + "{(";
                }
                virtual void visit_mult_middle(Mult* node) {
                    tree = tree + "\\cdot";
                }
                virtual void visit_mult_end(Mult* node) {
                    tree = tree + ")}";
                }

		void visit_div_begin(Div* node){
            tree = tree + "{\\frac";
	   	}
    
  		void visit_div_middle(Div* node){
    		}
    
  		void visit_div_end(Div* node){
            tree = tree + "}";
    		}
    
  		void visit_pow_begin(Pow* node){
            tree = tree + "{(";
    		}
    
  		void visit_pow_middle(Pow* node){
            tree = tree + "^";
    		}
  		void visit_pow_end(Pow* node){
            tree = tree + ")}";
   		 }
	
		string PrintLaTeX(Base* ptr){
			Iterator* x = new Iterator(ptr);
			for(x; !x->is_done();  x->next()){
				(x->current_node())->check(this, x->current_index());
			}
			delete x;
			return "$" + this->gettree() + "$";
		}	
	private:
		string tree;
//add all funcs from visitor.hpp and add two constructors
};

#endif
