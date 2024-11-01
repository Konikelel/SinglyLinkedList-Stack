#include <stack>
#include <gtest/gtest.h>
#include <string>

#include "stackFixture.hpp"

// EMPTY
TEST_F(StackFixture, Stack_IsEmpty)
{
    ASSERT_TRUE(stack.isEmpty());
    stack.push("1", 1);
    ASSERT_FALSE(stack.isEmpty());
}


// PEEK
TEST_F(StackFixture, Stack_PeekOneItem)
{
    int toCheck;
    ASSERT_FALSE(stack.peek(toCheck));
    stack.push("1", 1);
    ASSERT_TRUE(stack.peek(toCheck));
    ASSERT_EQ(toCheck, 1);
}

TEST_F(StackFixture, Stack_PeekMultipleItems)
{
    int toCheck;
    ASSERT_FALSE(stack.peek(toCheck));
    stack.push("1", 1);
    stack.push("1", 2);
    ASSERT_TRUE(stack.peek(toCheck));
    ASSERT_EQ(toCheck, 2);
}


// POP
TEST_F(StackFixture, Stack_PopEmpty)
{
    int toCheck;
    ASSERT_FALSE(stack.pop(toCheck));
}

TEST_F(StackFixture, Stack_PopNotEmpty)
{
    int toCheck;
    stack.push("1", 1);
    ASSERT_TRUE(stack.pop(toCheck));
    ASSERT_EQ(toCheck, 1);
    ASSERT_FALSE(stack.pop(toCheck));
    ASSERT_EQ(toCheck, 1);
    
    stack.push("1", 2);
    stack.push("2", 3);
    ASSERT_TRUE(stack.pop(toCheck));
    ASSERT_EQ(toCheck, 3);
}


// SIZE
TEST_F(StackFixture, Stack_Size)
{
    int temp;
    ASSERT_EQ(stack.size(), 0);
    stack.push("1", 2);
    ASSERT_EQ(stack.size(), 1);
    
    stack.push("2", 2);
    stack.push("1", 3);
    ASSERT_EQ(stack.size(), 3);
    
    stack.pop(temp);
    ASSERT_EQ(stack.size(), 2);
}