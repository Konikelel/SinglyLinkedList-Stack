#include "stackFixture.hpp"



void StackFixture::insertNodes(Stack<std::string, int> &stack, const unsigned int number, const int startNr)
{
    for (int nr = startNr; nr < number + startNr; nr++)
    {
        stack.push(std::to_string(nr), nr);
    }
}

Stack<std::string, int> StackFixture::createEmptyStack()
{
    return {};
}
