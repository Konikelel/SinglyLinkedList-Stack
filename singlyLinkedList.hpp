#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


template <typename Key, typename Info>
class SinglyLinkedList
{
public:
    SinglyLinkedList() : head(nullptr) {}
    SinglyLinkedList(const SinglyLinkedList& src);
    ~SinglyLinkedList();
    
    bool exist(const Key& key, unsigned int occ = 1) const;
    int getPosition(const Key& key, unsigned int occ = 1) const;
    bool get(const Key& key, Info& result, unsigned int occ = 1) const;
    bool getFirst(Info& result) const;
    void insertFront(const Key& key, const Info& info);
    bool insertAfter(const Key& key, const Info& info, const Key& where, unsigned int occ = 1);
    // void insertEnd(const Key& key, const Info& info); //MAYBE ADD POINTER TO END NODE, RATHER NOT EFFICIENT
    // bool insertBefore(const Key& key, const Info& info, const Key& where, unsigned int occ = 1); NOT EFFICIENT
    bool removeFront();
    void removeAll(const Key& key);
    bool remove(const Key& key, unsigned int occ = 1);
    [[nodiscard]] unsigned int size() const;
    [[nodiscard]] bool isEmpty() const;
    void clear();
    // void reverse();
    // void swap(SinglyLinkedList& other);
    void extend(const SinglyLinkedList& other);
    
    SinglyLinkedList& operator=(const SinglyLinkedList& other);
    SinglyLinkedList operator+(const SinglyLinkedList& other);
    SinglyLinkedList& operator+=(const SinglyLinkedList& other);

private:
    struct Node
    {
        Key key;
        Info info;
        Node *next;

        Node(const Key& key, const Info& info, Node *next = nullptr) : key(key), info(info), next(next) {}
    };
    Node *head;

    /*
     * Get node with key of n-th occurrence
     * If found return pointer to element and override pPrevNode with pointer to previous element
     * If not found return nullptr
     */
    Node* getNode(const Key& key, Node*& pPrevNode, unsigned int occ = 1) const;
    Node* getNode(const Key& key, unsigned int occ = 1) const;
    bool removeNode(Node*& pTarget);

    template <typename K, typename I>
    friend void concatenate(SinglyLinkedList<K, I>& seq1, SinglyLinkedList<K, I>& seq2, unsigned int len1, unsigned int len2, SinglyLinkedList<K, I>& seq);
};



template <typename Key, typename Info>
SinglyLinkedList<Key, Info>::SinglyLinkedList(const SinglyLinkedList& src): SinglyLinkedList()
{
    this->extend(src);
}

template <typename Key, typename Info>
SinglyLinkedList<Key, Info>::~SinglyLinkedList()
{
    this->clear();
}


template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::exist(const Key& key, const unsigned int occ) const
{
    return this->getNode(key, occ) != nullptr;
}

template <typename Key, typename Info>
int SinglyLinkedList<Key, Info>::getPosition(const Key& key, unsigned int occ) const
{
    int pos = 0;
    for (Node *pCurr = this->head; pCurr != nullptr; pCurr = pCurr->next, ++pos)
    {
        if (pCurr->key == key and --occ == 0)
        {
            return pos;
        }
    }
    return -1;
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::get(const Key& key, Info& result, const unsigned int occ) const
{
    Node *pNode = this->getNode(key, occ);
    if (pNode == nullptr)
    {
        return false;
    }
    result = pNode->info;
    return true;
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::getFirst(Info& result) const
{
    if (this->isEmpty())
    {
        return false;
    }
    result = this->head->info;
    return true;
}

template <typename Key, typename Info>
void SinglyLinkedList<Key, Info>::insertFront(const Key& key, const Info& info)
{
    this->head = new Node{key, info, this->head};
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::insertAfter(const Key& key, const Info& info, const Key& where, const unsigned int occ)
{
    Node *pPrev = this->getNode(where, occ);
    if (pPrev == nullptr)
    {
        return false;
    }
    pPrev->next = new Node{key, info, pPrev->next};
    return true;
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::removeFront()
{
    if (this->isEmpty())
    {
        return false;
    }
    const Node *pDelete = head;
    head = head->next;
    delete pDelete;
    return true;
}

template <typename Key, typename Info>
void SinglyLinkedList<Key, Info>::removeAll(const Key& key)
{
    for(Node *pPrev = nullptr, *pCurr = this->head; pCurr != nullptr; pCurr = pPrev == nullptr ? this->head : pPrev->next)
    {
        if (pCurr->key == key)
        {
            this->removeNode(pPrev == nullptr ? this->head : pPrev->next);
            continue;
        }
        pPrev = pCurr;
    }
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::remove(const Key& key, const unsigned int occ)
{
    Node *pPrev = nullptr;
    Node *pNode = this->getNode(key, pPrev, occ);
    if (pNode == nullptr)
    {
        return false;
    }
    
    return this->removeNode(pPrev == nullptr ? this->head : pPrev->next);
}

template <typename Key, typename Info>
[[nodiscard]] unsigned int SinglyLinkedList<Key, Info>::size() const
{
    unsigned int size = 0;
    for (Node *pCurr = this->head; pCurr != nullptr; pCurr = pCurr->next)
    {
        ++size;
    }
    return size;
}

template <typename Key, typename Info>
[[nodiscard]] bool SinglyLinkedList<Key, Info>::isEmpty() const
{
    return this->head == nullptr;
}

template <typename Key, typename Info>
void SinglyLinkedList<Key, Info>::clear()
{
    Node *pCurr;
    while ((pCurr = this->head) != nullptr)
    {
        this->head = this->head->next;
        delete pCurr;
    }
}

template <typename Key, typename Info>
void SinglyLinkedList<Key, Info>::extend(const SinglyLinkedList& other)
{
    if (other.isEmpty())
    {
        return;
    }
    
    Node *pThisCurr = this->head, *pOtherCurr = other.head;
    if (this->isEmpty())
    {
        this->head = pThisCurr = new Node{pOtherCurr->key, pOtherCurr->info};
        pOtherCurr = pOtherCurr->next;
    }
    else
    {
        while (pThisCurr->next != nullptr)
        {
            pThisCurr = pThisCurr->next;
        }
    }
    for (;pOtherCurr != nullptr; pOtherCurr = pOtherCurr->next, pThisCurr = pThisCurr->next)
    {
        pThisCurr->next = new Node{pOtherCurr->key, pOtherCurr->info};
    }
}

template <typename Key, typename Info>
typename SinglyLinkedList<Key, Info>::Node* SinglyLinkedList<Key, Info>::getNode(const Key& key, Node*& pPrevNode, unsigned int occ) const
{
    for (Node *pPrev = nullptr, *pCurr = this->head; pCurr != nullptr; pPrev = pCurr, pCurr = pCurr->next)
    {
        if (pCurr->key == key and --occ == 0)
        {
            return pPrevNode = pPrev, pCurr;
        }
    }
    return nullptr;
}

template <typename Key, typename Info>
typename SinglyLinkedList<Key, Info>::Node* SinglyLinkedList<Key, Info>::getNode(const Key& key, const unsigned int occ) const
{
    Node *pTemp;
    return this->getNode(key, pTemp, occ);
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::removeNode(Node*& pTarget)
{
    if (pTarget == nullptr)
    {
        return false;
    }
    
    const Node *toDelete = pTarget;
    pTarget = pTarget->next;
    delete toDelete;
    return true;
}


template <typename Key, typename Info>
SinglyLinkedList<Key, Info>& SinglyLinkedList<Key, Info>::operator=(const SinglyLinkedList& other)
{
    if (this != &other)
    {
        this->clear();
        this->extend(other);
    }
    return *this;
}

template <typename Key, typename Info>
SinglyLinkedList<Key, Info> SinglyLinkedList<Key, Info>::operator+(const SinglyLinkedList& other)
{
    auto out = SinglyLinkedList(*this);
    out.extend(other);
    return out;
}

template <typename Key, typename Info>
SinglyLinkedList<Key, Info>& SinglyLinkedList<Key, Info>::operator+=(const SinglyLinkedList& other)
{
    if (this != &other) {
        this->extend(other);
    }
    return *this;
}

#endif //SINGLY_LINKED_LIST_H