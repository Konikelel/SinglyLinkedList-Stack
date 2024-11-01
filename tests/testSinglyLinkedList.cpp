#include <gtest/gtest.h>
#include <string>

#include "singlyLinkedListFixture.hpp"


// CONSTRUCTOR
TEST_F(SinglyLikedListFixture, Constructor_InitializeEmpty)
{
    ASSERT_TRUE(singlyList.isEmpty());
}

// copy constructor
TEST_F(SinglyLikedListFixture, CopyConstructor_Empty)
{
    const auto toCheck = SinglyLinkedList(singlyList);
    ASSERT_TRUE(toCheck.isEmpty());
}

TEST_F(SinglyLikedListFixture, CopyConstructor_OneElementList)
{
    singlyList.insertFront("1", 1);
    auto copiedList = SinglyLinkedList(singlyList);

    int toCheckOne, toCheckTwo;
    ASSERT_EQ(singlyList.size(), copiedList.size());
    ASSERT_EQ(singlyList.getFirst(toCheckOne), copiedList.getFirst(toCheckTwo));
    ASSERT_EQ(toCheckOne, toCheckTwo);
}

TEST_F(SinglyLikedListFixture, Exist_MultipleElementsList)
{
    insertNodes(singlyList, 10);
    auto copiedList = SinglyLinkedList(singlyList);

    int toCheckOne, toCheckTwo;
    ASSERT_EQ(singlyList.size(), copiedList.size());
    ASSERT_EQ(singlyList.getFirst(toCheckOne), copiedList.getFirst(toCheckTwo));
    ASSERT_EQ(toCheckOne, toCheckTwo);
}


// EXISTS
TEST_F(SinglyLikedListFixture, Exist_Empty)
{
    ASSERT_FALSE(singlyList.exist("1"));
}

TEST_F(SinglyLikedListFixture, Exist_OneElementList)
{
    singlyList.insertFront("1", 1);
    
    ASSERT_TRUE(singlyList.exist("1"));
    ASSERT_FALSE(singlyList.exist("2"));
}


// GET
TEST_F(SinglyLikedListFixture, Get_Empty)
{
    int temp;
    ASSERT_FALSE(singlyList.get("1", temp));
}

TEST_F(SinglyLikedListFixture, Get_OneElementList)
{
    singlyList.insertFront("1", 1);
    
    int toCheck;
    ASSERT_TRUE(singlyList.get("1", toCheck));
    ASSERT_EQ(toCheck, 1);
}

TEST_F(SinglyLikedListFixture, Get_MultipleElementsList)
{
    insertNodes(singlyList, 10);
    
    int toCheck;
    ASSERT_TRUE(singlyList.get("0", toCheck));
    ASSERT_EQ(toCheck, 0);
    ASSERT_TRUE(singlyList.get("5", toCheck));
    ASSERT_EQ(toCheck, 5);
    ASSERT_FALSE(singlyList.get("10", toCheck));
    ASSERT_EQ(toCheck, 5);
}

TEST_F(SinglyLikedListFixture, Get_SpecificOccurance)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 2);

    int toCheck;
    ASSERT_TRUE(singlyList.get("1", toCheck, 2));
    ASSERT_EQ(toCheck, 1);
}

TEST_F(SinglyLikedListFixture, Get_SpecificOccuranceNotExist)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 2);

    int toCheck;
    ASSERT_FALSE(singlyList.get("1", toCheck, 3));
}


//GET FIRST
TEST_F(SinglyLikedListFixture, GetFirst_Empty)
{
    int temp;
    ASSERT_FALSE(singlyList.getFirst(temp));
}

TEST_F(SinglyLikedListFixture, GetFirst_OneElementList)
{
    insertNodes(singlyList, 1);
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 0);
}

TEST_F(SinglyLikedListFixture, GetFirst_MultipleElementList)
{
    insertNodes(singlyList, 4);
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 3);
}


// INSERT FRONT
TEST_F(SinglyLikedListFixture, InsertFront_Empty)
{
    ASSERT_TRUE(singlyList.isEmpty());
    singlyList.insertFront("1", 1);
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 1);
}

TEST_F(SinglyLikedListFixture, InsertFront_NotEmpty)
{
    ASSERT_TRUE(singlyList.isEmpty());
    singlyList.insertFront("1", 1);
    singlyList.insertFront("2", 2);
    singlyList.insertFront("3", 3);
    ASSERT_EQ(singlyList.size(), 3);

    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 3);
}


// INSERT AFTER
TEST_F(SinglyLikedListFixture, InsertAfter_Empty)
{
    ASSERT_FALSE(singlyList.insertAfter("1", 1, "2"));
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLikedListFixture, InsertAfter_FirstOccurance)
{
    singlyList.insertFront("1", 1);
    ASSERT_TRUE(singlyList.insertAfter("2", 2, "1"));
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 1);
    ASSERT_TRUE(singlyList.exist("2"));
}

TEST_F(SinglyLikedListFixture, InsertAfter_SpecificOccurrence)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 1);
    ASSERT_TRUE(singlyList.insertAfter("2", 2, "1", 2));

    ASSERT_TRUE(singlyList.exist("2"));
    singlyList.removeFront();
    singlyList.removeFront();
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 2);
}

TEST_F(SinglyLikedListFixture, InsertAfter_SpecificOccurrenceNotExists)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 1);
    ASSERT_FALSE(singlyList.insertAfter("2", 2, "1", 3));
    
    ASSERT_EQ(singlyList.size(), 2);
}


// REMOVE FRONT
TEST_F(SinglyLikedListFixture, RemoveFront_Empty)
{
    ASSERT_FALSE(singlyList.removeFront());
}

TEST_F(SinglyLikedListFixture, RemoveFront_OneElement)
{
    singlyList.insertFront("1", 1);
    ASSERT_TRUE(singlyList.removeFront());
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLikedListFixture, RemoveFront_MultipleElementsList)
{
    insertNodes(singlyList, 5);
    ASSERT_TRUE(singlyList.removeFront());
    ASSERT_EQ(singlyList.size(), 4);
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 3);
}


// REMOVE
// TODO: ADD TESTS FOR REMOVE

// specific occurrence
TEST_F(SinglyLikedListFixture, Remove_Occurance_Empty)
{
    ASSERT_FALSE(singlyList.remove("1", 1));
}

TEST_F(SinglyLikedListFixture, Remove_Occurance_OneElementList)
{
    singlyList.insertFront("1", 1);
    ASSERT_TRUE(singlyList.remove("1", 1));
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLikedListFixture, Remove_Occurance_MultipleElementsList)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 2);
    ASSERT_TRUE(singlyList.remove("1", 2));

    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 2);
}

TEST_F(SinglyLikedListFixture, Remove_Occurance_MultipleElementsListNotExists)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 2);
    ASSERT_FALSE(singlyList.remove("1", 3));

    ASSERT_EQ(singlyList.size(), 2);
}


// SIZE
TEST_F(SinglyLikedListFixture, Size_Empty)
{
    ASSERT_EQ(singlyList.size(), 0);
}

TEST_F(SinglyLikedListFixture, Size_OneElementList)
{
    singlyList.insertFront("1", 1);
    ASSERT_EQ(singlyList.size(), 1);
}

TEST_F(SinglyLikedListFixture, Size_MultipleElementsList)
{
    insertNodes(singlyList, 5);
    ASSERT_EQ(singlyList.size(), 5);
}


// IS EMPTY
TEST_F(SinglyLikedListFixture, IsEmpty_Empty)
{
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLikedListFixture, IsEmpty_NotEmpty)
{
    singlyList.insertFront("1", 1);
    ASSERT_FALSE(singlyList.isEmpty());
}


// CLEAR
TEST_F(SinglyLikedListFixture, Clear_Empty)
{
    singlyList.clear();
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLikedListFixture, Clear_NotEmpty)
{
    singlyList.insertFront("1", 1);
    singlyList.clear();
    ASSERT_TRUE(singlyList.isEmpty());
}


// EXTEND
TEST_F(SinglyLikedListFixture, Extend_EmptyListWithEmptyList)
{
    auto toExtend = createEmptyList();
    singlyList.extend(toExtend);
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLikedListFixture, Extend_EmptyListWithNoEmptyList)
{
    auto toExtend = createEmptyList();
    insertNodes(toExtend, 5);

    ASSERT_TRUE(singlyList.isEmpty());
    singlyList.extend(toExtend);
    ASSERT_EQ(singlyList.size(), toExtend.size());
    
    int toCheckOne, toCheckTwo;
    ASSERT_EQ(singlyList.getFirst(toCheckOne), singlyList.getFirst(toCheckTwo));
    ASSERT_EQ(toCheckOne, toCheckTwo);
}

TEST_F(SinglyLikedListFixture, Extend_NotEmptyListWithEmptyList)
{
    insertNodes(singlyList, 5);
    const auto toExtend = createEmptyList();

    singlyList.extend(toExtend);
    ASSERT_EQ(singlyList.size(), 5);
}

TEST_F(SinglyLikedListFixture, Extend_NotEmptyListWithNotEmptyList)
{
    insertNodes(singlyList, 5);
    auto toExtend = createEmptyList();
    insertNodes(toExtend, 4);

    singlyList.extend(toExtend);
    ASSERT_EQ(singlyList.size(), 9);
}