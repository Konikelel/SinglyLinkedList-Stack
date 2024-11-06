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
    singlyList.pushFront("1", 1);
    
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


// GET, Bool overload
TEST_F(SinglyLinkedListFixture, Singly_List_Get_BoolOverload_Empty)
{
    int temp;
    ASSERT_FALSE(singlyList.get("1", temp));
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_BoolOverload_OneElementList)
{
    singlyList.pushFront("1", 1);
    
    int toCheck;
    ASSERT_TRUE(singlyList.get("1", toCheck));
    ASSERT_EQ(toCheck, 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_BoolOverload_MultipleElementsList)
{
    singlyList.pushFront("0", 0);
    singlyList.pushFront("5", 5);
    
    
    int toCheck;
    ASSERT_TRUE(singlyList.get("0", toCheck));
    ASSERT_EQ(toCheck, 0);
    ASSERT_TRUE(singlyList.get("5", toCheck));
    ASSERT_EQ(toCheck, 5);
    ASSERT_FALSE(singlyList.get("10", toCheck));
    ASSERT_EQ(toCheck, 5);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_BoolOverload_SpecificOccurance)
{
    singlyList.pushFront("1", 1);
    singlyList.pushFront("1", 2);

    int toCheck;
    ASSERT_TRUE(singlyList.get("1", toCheck, 2));
    ASSERT_EQ(toCheck, 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_BoolOverload_SpecificOccuranceNotExist)
{
    singlyList.pushFront("1", 1);
    singlyList.pushFront("1", 2);

    int toCheck;
    ASSERT_FALSE(singlyList.get("1", toCheck, 3));
}

// GET, Info overload
TEST_F(SinglyLinkedListFixture, Singly_List_Get_InfoOverload_Empty)
{
    EXPECT_THROW(singlyList.get("1"), std::runtime_error);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_InfoOverload_OneElementList)
{
    singlyList.pushFront("1", 1);
    ASSERT_EQ(singlyList.get("1"), 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_InfoOverload_MultipleElementsList)
{
    singlyList.pushFront("0", 0);
    singlyList.pushFront("5", 5);
    
    ASSERT_EQ(singlyList.get("0"), 0);
    ASSERT_EQ(singlyList.get("5"), 5);
    EXPECT_THROW(singlyList.get("10"), std::runtime_error);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_InfoOverload_SpecificOccurance)
{
    singlyList.pushFront("1", 1);
    singlyList.pushFront("1", 2);

    ASSERT_EQ(singlyList.get("1", 2), 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Get_InfoOverload_SpecificOccuranceNotExist)
{
    singlyList.pushFront("1", 1);
    singlyList.pushFront("1", 2);
    
    EXPECT_THROW(singlyList.get("1", 3), std::runtime_error);
}

// GET FIRST, Bool overload
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

// GET FIRST, Info overload
TEST_F(SinglyLinkedListFixture, Singly_List_GetFirst_InfoOverload_Empty)
{
    EXPECT_THROW(singlyList.getFirst(), std::runtime_error);
}

TEST_F(SinglyLinkedListFixture, Singly_List_GetFirst_InfoOverload_OneElementList)
{
    singlyList.pushFront("1", 1);
    ASSERT_EQ(singlyList.getFirst(), 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_GetFirst_InfoOverload_MultipleElementsList)
{
    insertNodes(singlyList, 5);
    ASSERT_EQ(singlyList.getFirst(), 4);
}


// POP FIRST
TEST_F(SinglyLinkedListFixture, Singly_List_PopFirst_Empty)
{
    EXPECT_THROW(singlyList.popFirst(), std::runtime_error);
}

TEST_F(SinglyLinkedListFixture, Singly_List_PopFirst_OneElementList)
{
    singlyList.pushFront("1", 1);
    ASSERT_EQ(singlyList.popFirst(), 1);
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_PopFirst_MultipleElementsList)
{
    insertNodes(singlyList, 5);
    ASSERT_EQ(singlyList.popFirst(), 4);
    ASSERT_EQ(singlyList.size(), 4);
}


// PUSH FRONT
TEST_F(SinglyLinkedListFixture, Singly_List_PushFront_Empty)
{
    ASSERT_TRUE(singlyList.isEmpty());
    singlyList.pushFront("1", 1);
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 1);
}

TEST_F(SinglyLinkedListFixture, Singly_List_PushFront_NotEmpty)
{
    ASSERT_TRUE(singlyList.isEmpty());
    singlyList.pushFront("1", 1);
    singlyList.pushFront("2", 2);
    singlyList.pushFront("3", 3);
    ASSERT_EQ(singlyList.size(), 3);

    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 3);
}


// Push AFTER
TEST_F(SinglyLinkedListFixture, Singly_List_PushAfter_Empty)
{
    ASSERT_FALSE(singlyList.pushAfter("1", 1, "2"));
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_PushAfter_FirstOccurance)
{
    singlyList.pushFront("1", 1);
    ASSERT_TRUE(singlyList.pushAfter("2", 2, "1"));
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 1);
    ASSERT_TRUE(singlyList.exist("2"));
}

TEST_F(SinglyLinkedListFixture, Singly_List_PushAfter_SpecificOccurrence)
{
    singlyList.pushFront("1", 1);
    singlyList.pushFront("1", 1);
    ASSERT_TRUE(singlyList.pushAfter("2", 2, "1", 2));

    ASSERT_TRUE(singlyList.exist("2"));
    singlyList.removeFront();
    singlyList.removeFront();
    
    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 2);
}

TEST_F(SinglyLinkedListFixture, Singly_List_PushAfter_SpecificOccurrenceNotExists)
{
    singlyList.pushFront("1", 1);
    singlyList.pushFront("1", 1);
    ASSERT_FALSE(singlyList.pushAfter("2", 2, "1", 3));
    
    ASSERT_EQ(singlyList.size(), 2);
}


// REMOVE FRONT
TEST_F(SinglyLinkedListFixture, Singly_List_RemoveFront_Empty)
{
    ASSERT_FALSE(singlyList.removeFront());
}

TEST_F(SinglyLinkedListFixture, RemoveFront_OneElement)
{
    singlyList.pushFront("1", 1);
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
TEST_F(SinglyLinkedListFixture, Singly_List_Remove_All_Empty)
{
    ASSERT_FALSE(singlyList.remove("1", 1));
}

TEST_F(SinglyLinkedListFixture, Singly_List_Remove_All_NotEmpty)
{
    singlyList.pushFront("1", 1);
    singlyList.pushFront("2", 1);
    singlyList.pushFront("1", 2);
    singlyList.pushFront("2", 2);
    singlyList.pushFront("1", 1);

    ASSERT_FALSE(singlyList.removeAll("3"));
    ASSERT_TRUE(singlyList.removeAll("1"));
    ASSERT_EQ(singlyList.size(), 2);
    ASSERT_TRUE(singlyList.removeAll("2"));
    ASSERT_TRUE(singlyList.isEmpty());
}

// REMOVE
TEST_F(SinglyLinkedListFixture, Singly_List_Remove_Occurance_Empty)
{
    ASSERT_FALSE(singlyList.remove("1", 1));
}

TEST_F(SinglyLinkedListFixture, Singly_List_Remove_Occurance_OneElementList)
{
    singlyList.pushFront("1", 1);
    ASSERT_TRUE(singlyList.remove("1", 1));
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_Remove_Occurance_MultipleElementsList)
{
    singlyList.pushFront("1", 1);
    singlyList.pushFront("1", 2);
    ASSERT_TRUE(singlyList.remove("1", 2));

    int toCheck;
    ASSERT_TRUE(singlyList.getFirst(toCheck));
    ASSERT_EQ(toCheck, 2);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Remove_Occurance_MultipleElementsListNotExists)
{
    singlyList.pushFront("1", 1);
    singlyList.pushFront("1", 2);
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
    singlyList.pushFront("1", 1);
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
    singlyList.pushFront("1", 1);
    ASSERT_FALSE(singlyList.isEmpty());
}


// CLEAR
TEST_F(SinglyLinkedListFixture, Singly_List_Clear_Empty)
{
    ASSERT_FALSE(singlyList.clear());
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_Clear_NotEmpty)
{
    singlyList.pushFront("1", 1);
    ASSERT_TRUE(singlyList.clear());
    ASSERT_TRUE(singlyList.isEmpty());
}


// APPEND
TEST_F(SinglyLinkedListFixture, Singly_List_Append_EmptyListWithEmptyList)
{
    const auto toExtend = createEmptyList();
    singlyList.append(toExtend);
    ASSERT_TRUE(singlyList.isEmpty());
}

TEST_F(SinglyLinkedListFixture, Singly_List_Append_EmptyListWithNoEmptyList)
{
    auto toExtend = createEmptyList();
    insertNodes(toExtend, 5);

    ASSERT_TRUE(singlyList.isEmpty());
    singlyList.append(toExtend);
    ASSERT_EQ(singlyList.size(), toExtend.size());
    
    int toCheckOne, toCheckTwo;
    ASSERT_EQ(singlyList.getFirst(toCheckOne), singlyList.getFirst(toCheckTwo));
    ASSERT_EQ(toCheckOne, toCheckTwo);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Append_NotEmptyListWithEmptyList)
{
    insertNodes(singlyList, 5);
    const auto toExtend = createEmptyList();

    singlyList.append(toExtend);
    ASSERT_EQ(singlyList.size(), 5);
}

TEST_F(SinglyLinkedListFixture, Singly_List_Append_NotEmptyListWithNotEmptyList)
{
    insertNodes(singlyList, 5);
    auto toExtend = createEmptyList();
    insertNodes(toExtend, 4);

    singlyList.append(toExtend);
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
    singlyList.pushFront("1", 1);
    
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