#include "gtest.h"

#include "../mp2-lab3-stack/TStack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> st(5);

  ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack, can_add_element)
{
	TStack<int> st(1);
	st.push(1);
	EXPECT_EQ(1, st.top());
}

TEST(TStack, can_push_an_element)
{
	TStack<int> st(4);
	st.push(1);
	st.push(2);
	st.pop();
	EXPECT_EQ(1, st.top());
}

TEST(TStack, copied_stack_is_equal_to_source_one)
{
	int size = 2;
	TStack <int> st(size);
	for (int i = 0; i < size; i++) {
		st.push(i);
	}
	TStack <int> st1(st);
	for (int i = size-1; i >= size; i--) {
		EXPECT_EQ(i,st1.pop() );
	}
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	int size = 2;
	TStack <int> st(size);
	for (int i = 0; i < size; i++) {
		st.push(i);
	}
	TStack <int> st1(st);
	st.clear();
	for (int i = 0; i < size; i++) {
		st.push(i+3);
	}
	for (int i = 0; i < size; i++) {
		EXPECT_NE(st1.pop(), st.pop());
	}
}

TEST(TStack, can_check_for_emptiness)
{
	int size = 2;
	TStack<int> st(size);
	EXPECT_TRUE(st.isempty());
	st.push(1);
	st.push(2);
	EXPECT_TRUE(st.isfull());
}

TEST(TStack, throws_when_try_to_extract_from_the_empty)
{
	TStack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, throws_when_try_to_add_to_the_full)
{
	TStack<int> st(1);
	st.push(1);
	ASSERT_ANY_THROW(st.push(2));
}
