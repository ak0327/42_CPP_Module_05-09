#include <climits>
#include "RPN.hpp"
#include "gtest/gtest.h"

TEST(TestRPN, TestRpnOK) {
	RPN rpn;
	int res;

	rpn = RPN("8 9 * 9 - 9 - 9 - 4 - 1 +");
	res = 42;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("7 7 * 7 -");
	res = 42;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("0");
	res = 0;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("1");
	res = 1;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("9");
	res = 9;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("0");
	res = 0;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("0 2 - 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 1 + 0 1 - *");
	res = INT_MAX;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("0 2 - 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 *");
	res = INT_MIN;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("22222****");
	res = 32;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("222222*****");
	res = 64;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("2222222******");
	res = 128;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("22222222*******");
	res = 256;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());


	rpn = RPN("22222****0\t*");
	res = 0;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("1 2 + 3 4 - *");
	res = -3;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("2 4 - 2 4 4 4 4 4 * * * * * *");
	res = -4096;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("1 2 + 3 / 9 2 * + 1 2 - *");
	res = -19;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("1 2 + 2 /");
	res = 1;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("1 2 + 2 2 + /");
	res = 0;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("1 2 + 9 2 + /");
	res = 0;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());

	rpn = RPN("                  1\t1 +");
	res = 2;
	EXPECT_EQ(rpn.get_calc_result(), res);
	EXPECT_TRUE(rpn.is_succeed());
}

TEST(TestRPN, TestRpnError) {
	RPN rpn;

	rpn = RPN("(1 + 1)");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("                  ");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("a");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("12_");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("+");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("/ + 12");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("12+\v");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("1+");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("+1");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("123");
	EXPECT_FALSE(rpn.is_succeed());

	// overflow
	rpn = RPN("0 2 - 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 1 + 0 1 - *2*");
	EXPECT_FALSE(rpn.is_succeed());

	// underflow
	rpn = RPN("0 2 - 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 *2*");
	EXPECT_FALSE(rpn.is_succeed());

	// div by zero
	rpn = RPN("10/");
	EXPECT_FALSE(rpn.is_succeed());

	// div by zero
	rpn = RPN("19*0/");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("77*7-a");
	EXPECT_FALSE(rpn.is_succeed());

	rpn = RPN("12+++++++++++++++++++++++");
	EXPECT_FALSE(rpn.is_succeed());
}
