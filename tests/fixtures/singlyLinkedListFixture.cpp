#include "singlyLinkedListFixture.hpp"



void SinglyLikedListFixture::insertNodes(SinglyLinkedList<std::string, int> &list, const unsigned int number, const unsigned int startNr)
{
    for (unsigned int nr = startNr; nr < number + startNr; nr++)
    {
        list.insertFront(std::to_string(nr), static_cast<int>(nr));
    }
}

SinglyLinkedList<std::string, int> SinglyLikedListFixture::createEmptyList()
{
    return {};
}