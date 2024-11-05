#include <gtest/gtest.h>
#include <string>

#include "singlyLinkedListFixture.hpp"


// CONSTRUCTOR
TEST_F(SinglyLinkedListFixture, Singly_List_Constructor_InitializeEmpty)
{
    ASSERT_TRUE(singlyList.isEmpty());
}

// copy constructor
TEST_F(SinglyLinkedListFixture, Singly_List_CopyConstructor_Empty)
{
    const auto toCheck = SinglyLinkedList(singlyList);
    ASSERT_TRUE(toCheck.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_CopyConstructor_OneElementList)
{
    insertNodes(singlyList, 1);
    const auto copiedList = SinglyLinkedList(singlyList);

    int toCheckOne, toCheckTwo;
    ASSERT_EQ(singlyList.size(), copiedList.size());
    ASSERT_EQ(singlyList.getFirst(toCheckOne), copiedList.getFirst(toCheckTwo));
    ASSERT_EQ(toCheckOne, toCheckTwo);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Exist_MultipleElementsList)
{
    insertNodes(singlyList, 10);
    const auto copiedList = SinglyLinkedList(singlyList);

    int toCheckOne, toCheckTwo;
    ASSERT_EQ(singlyList.size(), copiedList.size());
    ASSERT_EQ(singlyList.getFirst(toCheckOne), copiedList.getFirst(toCheckTwo));
    ASSERT_EQ(toCheckOne, toCheckTwo);
}


// EXISTS
TEST_F(SinglyLinkedListFixture, Singly_List_Exist_Empty)
{
    ASSERT_FALSE(singlyList.exist("1"));
}

TEST_F(SinglyLinkedListFixture, Singly_List_Exist_OneElementList)
{
    singlyList.insertFront("1", 1);
    
    ASSERT_TRUE(singlyList.exist("1"));
    ASSERT_FALSE(singlyList.exist("2"));
}


// GET POSITION
TEST_F(SinglyLinkedListFixture, Singly_List_GetPosition_Empty)
{
    ASSERT_EQ(singlyList.getPosition("1"), -1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_GetPosition_Exists)
{
    insertNodes(singlyList, 2);
    ASSERT_EQ(singlyList.getPosition("1"), 0);
    ASSERT_EQ(singlyList.getPosition("0"), 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_GetPosition_NotExists)
{
    insertNodes(singlyList, 2);
    ASSERT_EQ(singlyList.getPosition("1"), 0);
    ASSERT_EQ(singlyList.getPosition("3"), -1);
}


// GET
TEST_F(SinglyLinkedListFixture, Singly_List_Get_Empty)
{
    int temp;
    ASSERT_FALSE(singlyList.get("1", temp));
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_OneElementList)
{
    singlyList.insertFront("1", 1);
    
    int toCheck;
    ASSERT_TRUE(singlyList.get("1", toCheck));
    ASSERT_EQ(toCheck, 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_MultipleElementsList)
{
    singlyList.insertFront("0", 0);
    singlyList.insertFront("5", 5);
    
    
    int toCheck;
    ASSERT_TRUE(singlyList.get("0", toCheck));
    ASSERT_EQ(toCheck, 0);
    ASSERT_TRUE(singlyList.get("5", toCheck));
    ASSERT_EQ(toCheck, 5);
    ASSERT_FALSE(singlyList.get("10", toCheck));
    ASSERT_EQ(toCheck, 5);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_SpecificOccurance)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 2);

    int toCheck;
    ASSERT_TRUE(singlyList.get("1", toCheck, 2));
    ASSERT_EQ(toCheck, 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_SpecificOccuranceNotExist)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 2);

    int toCheck;
    ASSERT_FALSE(singlyList.get("1", toCheck, 3));
}


//GET FIRST
TEST_F(SinglyLinkedListFixture, Singly_List_GetFirst_Empty)
{
    int temp;
    ASSERT_FALSE(singlyList.getFirst(temp));
}

TEST_F(SinglyLinkedListFixture, Singly_List_GetFirst_OneElementList)
{
    insertNodes(singlyList, 1);
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 0);
}

TEST_F(SinglyLinkedListFixture, Singly_List_GetFirst_MultipleElementList)
{
    insertNodes(singlyList, 4);
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 3);
}


// INSERT FRONT
TEST_F(SinglyLinkedListFixture, Singly_List_InsertFront_Empty)
{
    ASSERT_TRUE(singlyList.isEmpty());
    singlyList.insertFront("1", 1);
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_InsertFront_NotEmpty)
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
TEST_F(SinglyLinkedListFixture, Singly_List_InsertAfter_Empty)
{
    ASSERT_FALSE(singlyList.insertAfter("1", 1, "2"));
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_InsertAfter_FirstOccurance)
{
    singlyList.insertFront("1", 1);
    ASSERT_TRUE(singlyList.insertAfter("2", 2, "1"));
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 1);
    ASSERT_TRUE(singlyList.exist("2"));
}

TEST_F(SinglyLinkedListFixture, Singly_List_InsertAfter_SpecificOccurrence)
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

TEST_F(SinglyLinkedListFixture, Singly_List_InsertAfter_SpecificOccurrenceNotExists)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 1);
    ASSERT_FALSE(singlyList.insertAfter("2", 2, "1", 3));
    
    ASSERT_EQ(singlyList.size(), 2);
}


// REMOVE FRONT
TEST_F(SinglyLinkedListFixture, Singly_List_RemoveFront_Empty)
{
    ASSERT_FALSE(singlyList.removeFront());
}

TEST_F(SinglyLinkedListFixture, RemoveFront_OneElement)
{
    singlyList.insertFront("1", 1);
    ASSERT_TRUE(singlyList.removeFront());
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_RemoveFront_MultipleElementsList)
{
    insertNodes(singlyList, 5);
    ASSERT_TRUE(singlyList.removeFront());
    ASSERT_EQ(singlyList.size(), 4);
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 3);
}


// REMOVE ALL
TEST_F(SinglyLinkedListFixture, Singly_List_Remove_Empty)
{
    ASSERT_FALSE(singlyList.remove("1", 1));
}

TEST_F(SinglyLinkedListFixture, Singly_List_Remove_NotEmpty)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("2", 1);
    singlyList.insertFront("1", 2);
    singlyList.insertFront("2", 2);
    singlyList.insertFront("1", 1);

    singlyList.removeAll("1");
    ASSERT_EQ(singlyList.size(), 2);
    singlyList.removeAll("2");
    ASSERT_TRUE(singlyList.isEmpty());
}

// REMOVE
TEST_F(SinglyLinkedListFixture, Singly_List_Remove_Occurance_Empty)
{
    ASSERT_FALSE(singlyList.remove("1", 1));
}

TEST_F(SinglyLinkedListFixture, Singly_List_Remove_Occurance_OneElementList)
{
    singlyList.insertFront("1", 1);
    ASSERT_TRUE(singlyList.remove("1", 1));
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_Remove_Occurance_MultipleElementsList)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 2);
    ASSERT_TRUE(singlyList.remove("1", 2));

    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 2);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Remove_Occurance_MultipleElementsListNotExists)
{
    singlyList.insertFront("1", 1);
    singlyList.insertFront("1", 2);
    ASSERT_FALSE(singlyList.remove("1", 3));

    ASSERT_EQ(singlyList.size(), 2);
}


// SIZE
TEST_F(SinglyLinkedListFixture, Singly_List_Size_Empty)
{
    ASSERT_EQ(singlyList.size(), 0);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Size_OneElementList)
{
    singlyList.insertFront("1", 1);
    ASSERT_EQ(singlyList.size(), 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Size_MultipleElementsList)
{
    insertNodes(singlyList, 5);
    ASSERT_EQ(singlyList.size(), 5);
}


// IS EMPTY
TEST_F(SinglyLinkedListFixture, Singly_List_IsEmpty_Empty)
{
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_IsEmpty_NotEmpty)
{
    singlyList.insertFront("1", 1);
    ASSERT_FALSE(singlyList.isEmpty());
}


// CLEAR
TEST_F(SinglyLinkedListFixture, Singly_List_Clear_Empty)
{
    singlyList.clear();
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_Clear_NotEmpty)
{
    singlyList.insertFront("1", 1);
    singlyList.clear();
    ASSERT_TRUE(singlyList.isEmpty());
}


// EXTEND
TEST_F(SinglyLinkedListFixture, Singly_List_Extend_EmptyListWithEmptyList)
{
    const auto toExtend = createEmptyList();
    singlyList.extend(toExtend);
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_Extend_EmptyListWithNoEmptyList)
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

TEST_F(SinglyLinkedListFixture, Singly_List_Extend_NotEmptyListWithEmptyList)
{
    insertNodes(singlyList, 5);
    const auto toExtend = createEmptyList();

    singlyList.extend(toExtend);
    ASSERT_EQ(singlyList.size(), 5);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Extend_NotEmptyListWithNotEmptyList)
{
    insertNodes(singlyList, 5);
    auto toExtend = createEmptyList();
    insertNodes(toExtend, 4);

    singlyList.extend(toExtend);
    ASSERT_EQ(singlyList.size(), 9);
}


// OPERATOR =
TEST_F(SinglyLinkedListFixture, Singly_List_AssignmentOperator_SameList)
{
    insertNodes(singlyList, 5);
    
    singlyList = singlyList;  // NOLINT
    ASSERT_EQ(singlyList.size(), 5);
}

TEST_F(SinglyLinkedListFixture, Singly_List_AssignmentOperator_DiffrentListEmpty)
{
    insertNodes(singlyList, 5);
    const auto toCheck = createEmptyList();
    
    singlyList = toCheck;
    ASSERT_EQ(singlyList.size(), 0);
}

TEST_F(SinglyLinkedListFixture, Singly_List_AssignmentOperator_DiffrentListNotEmpty)
{
    insertNodes(singlyList, 5);
    auto toCheck = createEmptyList();
    insertNodes(toCheck, 3);

    singlyList = toCheck;
    int toCheckOne, toCheckTwo;
    ASSERT_EQ(singlyList.size(), 3);
    ASSERT_EQ(singlyList.getFirst(toCheckOne), toCheck.getFirst(toCheckTwo));
    ASSERT_EQ(toCheckOne, toCheckTwo);
}


// OPERATOR +
TEST_F(SinglyLinkedListFixture, Singly_List_AdditionOperator_SameList)
{
    insertNodes(singlyList, 5);

    const auto toCheck = singlyList + singlyList;
    ASSERT_EQ(toCheck.size(), 5 * 2);
}

TEST_F(SinglyLinkedListFixture, Singly_List_AdditionOperator_DiffrentListEmpty)
{
    insertNodes(singlyList, 5);
    const auto singlyListOther = createEmptyList();
    
    const auto toCheck = singlyList + singlyListOther;
    ASSERT_EQ(toCheck.size(), 5);
    
}

TEST_F(SinglyLinkedListFixture, Singly_List_AdditionOperator_DiffrentListNotEmpty)
{
    insertNodes(singlyList, 5);
    auto singlyListOther = createEmptyList();
    insertNodes(singlyListOther, 3);

    const auto toCheck = singlyList + singlyListOther;
    ASSERT_EQ(toCheck.size(), 5 + 3);
}


// OPERATOR +=
TEST_F(SinglyLinkedListFixture, Singly_List_AdditionAssignmentOperator_SameList)
{
    insertNodes(singlyList, 5);

    singlyList += singlyList;
    ASSERT_EQ(singlyList.size(), 5);
}

TEST_F(SinglyLinkedListFixture, Singly_List_AdditionAssignmentOperator_DiffrentListEmpty)
{
    insertNodes(singlyList, 5);
    const auto singlyListOther = createEmptyList();
    
    singlyList += singlyListOther;
    ASSERT_EQ(singlyList.size(), 5);
}

TEST_F(SinglyLinkedListFixture, Singly_List_AdditionAssignmentOperator_DiffrentListNotEmpty)
{
    insertNodes(singlyList, 5);
    auto singlyListOther = createEmptyList();
    insertNodes(singlyListOther, 3);

    singlyList += singlyListOther;
    ASSERT_EQ(singlyList.size(), 5 + 3);
}

// OPERATOR <<
TEST_F(SinglyLinkedListFixture, Singly_List_OstreamOperator_Empty)
{
    std::stringstream ss;
    ss << singlyList;
    ASSERT_EQ(ss.str(), "");
}

TEST_F(SinglyLinkedListFixture, Singly_List_OstreamOperator_OneElementList)
{
    singlyList.insertFront("1", 1);
    
    std::stringstream ss;
    ss << singlyList;
    ASSERT_EQ(ss.str(), "1: 1\n");
}

TEST_F(SinglyLinkedListFixture, Singly_List_OstreamOperator_MultipleElementsList)
{
    insertNodes(singlyList, 5);
    
    std::stringstream ss;
    ss << singlyList;
    ASSERT_EQ(ss.str(), "4: 4\n3: 3\n2: 2\n1: 1\n0: 0\n");
}