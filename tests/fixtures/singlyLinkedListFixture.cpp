#include "singlyLinkedListFixture.hpp"



void SinglyLikedListFixture::insertNodes(SinglyLinkedList<std::string, int> &list, const unsigned int number)
{
    for (int nr = 0; nr < number; nr++)
    {
        list.insertFront(std::to_string(nr), nr);
    }
}

SinglyLinkedList<std::string, int> SinglyLikedListFixture::createEmptyList()
{
    return {};
}