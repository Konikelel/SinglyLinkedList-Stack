#include <gtest/gtest.h>
#include <string>

#include "concatenate.hpp"
#include "singlyLinkedListFixture.hpp"


TEST_F(SinglyLikedListFixture, Concatenate_NotEmpty)
{
    auto singlyList2 = createEmptyList();
    auto toCheck = createEmptyList();
    insertNodes(singlyList, 13, 0);
    insertNodes(singlyList2, 7, 20);
    
    concatenate(singlyList, singlyList2, 2, 3, toCheck);
    ASSERT_EQ(singlyList.size(), 0);
    ASSERT_EQ(singlyList2.size(), 0);
    ASSERT_EQ(toCheck.size(), 20);
    ASSERT_EQ(toCheck.getPosition("24"), 4);
    ASSERT_EQ(toCheck.getPosition("20"), 12);
    ASSERT_EQ(toCheck.getPosition("2"), 17);
    ASSERT_EQ(toCheck.getPosition("0"), 19);
}

TEST_F(SinglyLikedListFixture, Concatenate_OneLenZero)
{
    auto singlyList2 = createEmptyList();
    auto toCheck = createEmptyList();
    insertNodes(singlyList, 6, 0);
    insertNodes(singlyList2, 8, 0);
    
    concatenate(singlyList, singlyList2, 2, 0, toCheck);
    ASSERT_EQ(singlyList.size(), 0);
    ASSERT_EQ(singlyList2.size(), 0);
    ASSERT_EQ(toCheck.size(), 6);
    ASSERT_EQ(toCheck.getPosition("0"), 5);
    ASSERT_EQ(toCheck.getPosition("5"), 0);
    ASSERT_EQ(toCheck.getPosition("4"), 1);
}

TEST_F(SinglyLikedListFixture, Concatenate_LenGreaterThanSizeList)
{
    auto singlyList2 = createEmptyList();
    auto toCheck = createEmptyList();
    insertNodes(singlyList, 6, 0);
    insertNodes(singlyList2, 8, 0);
    
    concatenate(singlyList, singlyList2, 20, 0, toCheck);
    ASSERT_EQ(singlyList.size(), 0);
    ASSERT_EQ(singlyList2.size(), 0);
    ASSERT_EQ(toCheck.size(), 6);
    ASSERT_EQ(toCheck.getPosition("0"), 5);
    ASSERT_EQ(toCheck.getPosition("5"), 0);
    ASSERT_EQ(toCheck.getPosition("4"), 1);
}

TEST_F(SinglyLikedListFixture, Concatenate_TwoLenZero)
{
    auto singlyList2 = createEmptyList();
    auto toCheck = createEmptyList();
    insertNodes(singlyList, 6, 0);
    insertNodes(singlyList, 8, 0);
    
    concatenate(singlyList, singlyList2, 0, 0, toCheck);
    ASSERT_EQ(singlyList.size(), 0);
    ASSERT_EQ(singlyList2.size(), 0);
    ASSERT_EQ(toCheck.size(), 0);
}