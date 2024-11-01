#include "singlyLinkedListFixture.hpp"



void SinglyLikedListFixture::insertNodes(SinglyLinkedList<std::string, int> &list, const unsigned int number, const int startNr)
{
    for (int nr = startNr; nr < number + startNr; nr++)
    {
        list.insertFront(std::to_string(nr), nr);
    }
}

SinglyLinkedList<std::string, int> SinglyLikedListFixture::createEmptyList()
{
    return {};
}