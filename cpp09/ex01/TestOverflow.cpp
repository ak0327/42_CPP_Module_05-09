#include <climits>
#include <string>
#include "RPN.hpp"
#include "gtest/gtest.h"

TEST(TestValidator, IsAddOverflow) {
	EXPECT_TRUE(RPN::is_add_overflow(INT_MAX, 1));
	EXPECT_TRUE(RPN::is_add_overflow(1, INT_MAX));
	EXPECT_TRUE(RPN::is_add_overflow(INT_MAX, INT_MAX));

	EXPECT_FALSE(RPN::is_add_overflow(INT_MAX, 0));
	EXPECT_FALSE(RPN::is_add_overflow(INT_MAX, -1));
	EXPECT_FALSE(RPN::is_add_overflow(INT_MAX, INT_MIN));
	EXPECT_FALSE(RPN::is_add_overflow(INT_MAX - 1, 1));
}

TEST(TestValidator, IsAddUnderflow) {
	EXPECT_TRUE(RPN::is_add_underflow(INT_MIN, -1));
	EXPECT_TRUE(RPN::is_add_underflow(INT_MIN, INT_MIN));

	EXPECT_FALSE(RPN::is_add_underflow(INT_MIN, 0));
	EXPECT_FALSE(RPN::is_add_underflow(INT_MIN, 1));
	EXPECT_FALSE(RPN::is_add_underflow(INT_MIN + 1, 1));
}

TEST(TestValidator, IsSubOverflow) {
	EXPECT_TRUE(RPN::is_sub_overflow(INT_MAX, -1));
	EXPECT_TRUE(RPN::is_sub_overflow(INT_MAX, INT_MIN));

	EXPECT_FALSE(RPN::is_sub_overflow(INT_MAX, 0));
	EXPECT_FALSE(RPN::is_sub_overflow(INT_MAX, INT_MAX));
	EXPECT_FALSE(RPN::is_sub_overflow(-1, INT_MAX));
	EXPECT_FALSE(RPN::is_sub_overflow(INT_MIN, INT_MAX));
}

TEST(TestValidator, IsSubUnderflow) {
	EXPECT_TRUE(RPN::is_sub_underflow(INT_MIN, 1));
	EXPECT_TRUE(RPN::is_sub_underflow(INT_MIN, INT_MAX));

	EXPECT_FALSE(RPN::is_sub_underflow(INT_MIN, 0));
	EXPECT_FALSE(RPN::is_sub_underflow(0, INT_MAX));
	EXPECT_FALSE(RPN::is_sub_underflow(INT_MIN, INT_MIN));
}

TEST(TestValidator, IsMulOverflow) {
	EXPECT_TRUE(RPN::is_mul_overflow(INT_MAX, 2));
	EXPECT_TRUE(RPN::is_mul_overflow(INT_MAX / 2 + 1, 2));
	EXPECT_TRUE(RPN::is_mul_overflow(INT_MIN, -1));
	EXPECT_TRUE(RPN::is_mul_overflow(INT_MIN, -2));
	EXPECT_TRUE(RPN::is_mul_overflow(INT_MIN, -3));
	EXPECT_TRUE(RPN::is_mul_overflow(INT_MIN + 1, -2));
	EXPECT_TRUE(RPN::is_mul_overflow(INT_MIN + 10, -2));
	EXPECT_TRUE(RPN::is_mul_overflow(INT_MIN, INT_MIN));
	EXPECT_TRUE(RPN::is_mul_overflow(INT_MAX, INT_MAX));
	EXPECT_TRUE(RPN::is_mul_overflow(INT_MAX - 1, INT_MIN + 1));

	EXPECT_FALSE(RPN::is_mul_overflow(INT_MAX, 0));
	EXPECT_FALSE(RPN::is_mul_overflow(INT_MAX / 2, 2));
	EXPECT_FALSE(RPN::is_mul_overflow(INT_MAX / 2 - 1, 2));
	EXPECT_FALSE(RPN::is_mul_overflow(2, -2));
	EXPECT_FALSE(RPN::is_mul_overflow(-2, 2));
}

TEST(TestValidator, IsMulUnderflow) {
	EXPECT_TRUE(RPN::is_mul_underflow(INT_MIN, 2));
	EXPECT_TRUE(RPN::is_mul_underflow(INT_MIN, INT_MAX));
	EXPECT_TRUE(RPN::is_mul_underflow(INT_MAX / 2 + 2, -2));
	EXPECT_TRUE(RPN::is_mul_underflow(INT_MAX - 1, -2));

	EXPECT_FALSE(RPN::is_mul_underflow(INT_MIN, 0));
	EXPECT_FALSE(RPN::is_mul_underflow(INT_MIN, -1));
	EXPECT_FALSE(RPN::is_mul_underflow(2, -2));
	EXPECT_FALSE(RPN::is_mul_underflow(-2, 2));
}

TEST(TestValidator, IsDivOverflow) {
	EXPECT_TRUE(RPN::is_div_overflow(INT_MIN, -1));

	EXPECT_FALSE(RPN::is_div_overflow(INT_MAX, INT_MIN));
	EXPECT_FALSE(RPN::is_div_overflow(INT_MIN, INT_MAX));
	EXPECT_FALSE(RPN::is_div_overflow(INT_MIN, INT_MIN));
	EXPECT_FALSE(RPN::is_div_overflow(INT_MAX, -1));
}
