#include "gtest.h"

#include "../mp2-lab3-stack/TCalculator.h"

TEST(TCalculator, can_create_calculator)
{
  ASSERT_NO_THROW(TCalculator m);
}

TEST(TCalculator, can_create_copied_calculator)
{
  TCalculator m;

  ASSERT_NO_THROW(TCalculator m1(m));
}

TEST(TCalculator, can_set_and_get_string)
{
	TCalculator  calc;
	std::string expr = "2+2";
	ASSERT_NO_THROW(calc.Setexpr(expr));
	EXPECT_EQ(calc.GetExpr(),expr);
}

TEST(TCalculator, copied_calculator_is_equal_to_source_one)
{
	TCalculator v;
	v.Setexpr("2+2");
	TCalculator v1(v);
	EXPECT_EQ(v1.GetExpr(), v.GetExpr());
}

TEST(TCalculator, copied_calculator_has_its_own_memory)
{
	TCalculator v;
	v.Setexpr("2+2");
	TCalculator v1(v);
	v.Setexpr("4+4");
	EXPECT_NE(v1.GetExpr(), v.GetExpr());
}

TEST(TCalculator, can_check_the_brackets_in_the_string)
{
	TCalculator v;
	v.Setexpr("(2+2)/3");
	EXPECT_TRUE(v.check());
	v.Setexpr(")4+4");
	EXPECT_FALSE(v.check());
}

TEST(TCalculator, can_convert_into_postfix)
{
	TCalculator v;
	v.Setexpr("1+2-3");
	v.ToPostfix();
	EXPECT_EQ(v.GetPostfix(),"1 2 +3-");
}

TEST(TCalculator, can_count_the_expression)
{
	TCalculator v;
	v.Setexpr("1+2-3");
	v.ToPostfix();
	EXPECT_EQ(v.calc(),0);
}

TEST(TCalculator, throws_when_try_to_count_an_incorrect_expression)
{
	TCalculator v;
	v.Setexpr("2/-3");
	v.ToPostfix();
	ASSERT_ANY_THROW(v.calc());
}



