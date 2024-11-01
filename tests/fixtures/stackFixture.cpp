#include "stackFixture.hpp"



void StackFixture::insertNodes(Stack<std::string, int> &stack, const unsigned int number, const unsigned int startNr)
{
    for (unsigned int nr = startNr; nr < number + startNr; nr++)
    {
        stack.push(std::to_string(nr), static_cast<int>(nr));
    }
}

Stack<std::string, int> StackFixture::createEmptyStack()
{
    return {};
}
