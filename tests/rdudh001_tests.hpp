#ifndef __RDUDH001_TESTS_HPP__
#define __RDUDH001_TESTS_HPP__

#include "../header/base.hpp"
#include "../header/add.hpp"
#include "../header/sub.hpp"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/pow.hpp"
#include "../header/op.hpp"
#include "../header/rand.hpp"

TEST(Children, Add) {
	Add* sign = new Add(new Op(1), new Op(2));

	EXPECT_EQ(sign->number_of_children(), 2);
	delete sign;
}

TEST(Children, Sub) {
        Sub* sign = new Sub(new Op(1), new Op(2));

        EXPECT_EQ(sign->number_of_children(), 2);
        delete sign;
}

TEST(Children, Mult) {
        Mult* sign = new Mult(new Op(1), new Op(2));

        EXPECT_EQ(sign->number_of_children(), 2);
        delete sign;
}

TEST(Children, Div) {
        Div* sign = new Div(new Op(1), new Op(2));

        EXPECT_EQ(sign->number_of_children(), 2);
        delete sign;
}

TEST(Children, Pow) {
        Pow* sign = new Pow(new Op(1), new Op(2));

        EXPECT_EQ(sign->number_of_children(), 2);
        delete sign;
}

TEST(Children, Op) {
        Op* sign = new Op(2.1);

        EXPECT_EQ(sign->number_of_children(), 0);
        delete sign;
}


#endif
