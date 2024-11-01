#ifndef STACK_FIXTURE_H
#define STACK_FIXTURE_H


#include <gtest/gtest.h>
#include <string>

#include "stack.hpp"


class StackFixture : public testing::Test {
protected:
    Stack<std::string, int> stack;

    static void insertNodes(Stack<std::string, int> &stack, unsigned int number, unsigned int startNr = 0);

    static Stack<std::string, int> createEmptyStack();
};



#endif //STACK_FIXTURE_H
