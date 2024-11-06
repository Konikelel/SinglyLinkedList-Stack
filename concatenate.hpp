#ifndef CONCATENATE_H
#define CONCATENATE_H

#include "singlyLinkedList.hpp"

template <typename Key, typename Info>
void concatenate(SinglyLinkedList <Key, Info>& seq1, SinglyLinkedList <Key, Info>& seq2,
                 const unsigned int len1, const unsigned int len2, SinglyLinkedList <Key, Info>& seq)
{
    if ((seq1.isEmpty() or len1 == 0) and (seq2.isEmpty() or len2 == 0))
    {
        seq1.clear(), seq2.clear();
        return;
    }
    
    auto seqBuffer = SinglyLinkedList<Key, Info>();
    for(unsigned int nr = 0; nr < len1 and !seq1.isEmpty(); nr++)
    {
        seqBuffer.pushFront(seq1.head->key, seq1.head->info);
        seq1.removeFront();
    }
    for(unsigned int nr = 0; nr < len2 and !seq2.isEmpty(); nr++)
    {
        seqBuffer.pushFront(seq2.head->key, seq2.head->info);
        seq2.removeFront();
    }
    
    concatenate(seq1, seq2, len1, len2, seq);
    while(!seqBuffer.isEmpty())
    {
        seq.pushFront(seqBuffer.head->key, seqBuffer.head->info);
        seqBuffer.removeFront();
    }
}

#endif //CONCATENATE_H
