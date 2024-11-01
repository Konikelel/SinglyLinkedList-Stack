#ifndef SINGLY_LIKED_LIST_FIXTURE_H
#define SINGLY_LIKED_LIST_FIXTURE_H


#include <gtest/gtest.h>
#include <string>

#include "singlyLinkedList.hpp"


class SinglyLikedListFixture : public testing::Test
{
protected:
    SinglyLinkedList<std::string, int> singlyList;

    static void insertNodes(SinglyLinkedList<std::string, int> &list, unsigned int number, const int startNr = 0);

    static SinglyLinkedList<std::string, int> createEmptyList();
};


#endif //SINGLY_LIKED_LIST_FIXTURE_H
