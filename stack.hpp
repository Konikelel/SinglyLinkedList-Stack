#ifndef STACK_H
#define STACK_H
#include "singlyLinkedList.hpp"


template <typename Key, typename Info>
class Stack
{
public:
    Stack() = default;

    void push(const Key& key, const Info& info);
    bool peek(Info& result);
    bool pop(Info& result);
    bool isEmpty();
    int size();
private:
    SinglyLinkedList<Key, Info> list;
};

template <typename Key, typename Info>
void Stack<Key, Info>::push(const Key& key, const Info& info)
{
    list.insertFront(key, info);
}

template <typename Key, typename Info>
bool Stack<Key, Info>::peek(Info& result)
{
    return list.getFirst(result);
}

template <typename Key, typename Info>
bool Stack<Key, Info>::pop(Info& result)
{
    list.getFirst(result);
    return list.removeFront();
}

template <typename Key, typename Info>
bool Stack<Key, Info>::isEmpty()
{
    return list.isEmpty();
}

template <typename Key, typename Info>
int Stack<Key, Info>::size()
{
    return list.size();
}
#endif //STACK_H
