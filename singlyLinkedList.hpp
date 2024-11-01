#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


template <typename Key, typename Info>
class SinglyLinkedList
{
public:
    SinglyLinkedList() : head(nullptr) {}
    SinglyLinkedList(const SinglyLinkedList& src);
    ~SinglyLinkedList();
    
    bool exist(const Key& key, unsigned int occ = 1);
    bool get(const Key& key, Info& result, unsigned int occ = 1);
    bool getFirst(Info& result);
    void insertFront(const Key& key, const Info& info);
    bool insertAfter(const Key& key, const Info& info, const Key& where, unsigned int occ = 1);
    // void insertEnd(const Key& key, const Info& info); //MAYBE ADD POINTER TO END NODE, RATHER NOT EFFICIENT
    // bool insertBefore(const Key& key, const Info& info, const Key& where, unsigned int occ = 1); NOT EFFICIENT
    bool removeFront();
    void remove(const Key& key);
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
    Node* get(const Key& key, Node*& pPrevNode, unsigned int occ = 1);
    Node* get(const Key& key, unsigned int occ = 1);
    bool remove(Node*& pTarget);
};



template <typename Key, typename Info>
SinglyLinkedList<Key, Info>::SinglyLinkedList(const SinglyLinkedList& src)
{
    Node *pPrev = nullptr;
    for (Node *pCurr = src.head; pCurr != nullptr; pCurr = pCurr->next)
    {
        if (pPrev == nullptr)
        {
            this->head = new Node{pCurr->key, pCurr->info};
            pPrev = this->head;
        }
        else
        {
            pPrev->next = new Node{pCurr->key, pCurr->info};
            pPrev = pPrev->next;
        }
    }
}

template <typename Key, typename Info>
SinglyLinkedList<Key, Info>::~SinglyLinkedList()
{
    this->clear();
}


template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::exist(const Key& key, const unsigned int occ)
{
    return this->get(key, occ) != nullptr;
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::get(const Key& key, Info& result, const unsigned int occ)
{
    Node *pNode = this->get(key, occ);
    if (pNode == nullptr)
    {
        return false;
    }
    result = pNode->info;
    return true;
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::getFirst(Info& result)
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
    Node *pPrev = this->get(where, occ);
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
void SinglyLinkedList<Key, Info>::remove(const Key& key)
{
    for(Node *pPrev = nullptr, *pCurr = this->head; pCurr != nullptr; pPrev = pCurr, pCurr = pCurr->next)
    {
        if (pCurr->key == key)
        {
            this->remove(pPrev == nullptr ? this->head : pPrev->next);
        }
    }
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::remove(const Key& key, const unsigned int occ)
{
    Node *pPrev = nullptr;
    Node *pNode = this->get(key, pPrev, occ);
    if (pNode == nullptr)
    {
        return false;
    }
    
    return this->remove(pPrev == nullptr ? this->head : pPrev->next);
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
void SinglyLinkedList<Key, Info>::extend(const SinglyLinkedList<Key, Info>& other)
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
typename SinglyLinkedList<Key, Info>::Node* SinglyLinkedList<Key, Info>::get(const Key& key, Node*& pPrevNode, unsigned int occ)
{
    for (Node *pPrev = nullptr, *pCurr = this->head; pCurr != nullptr; pPrev = pCurr, pCurr = pCurr->next)
    {
        if (pCurr->key == key && --occ == 0)
        {
            return pPrevNode = pPrev, pCurr;
        }
    }
    return nullptr;
}

template <typename Key, typename Info>
typename SinglyLinkedList<Key, Info>::Node* SinglyLinkedList<Key, Info>::get(const Key& key, const unsigned int occ)
{
    Node *pTemp;
    return this->get(key, pTemp, occ);
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::remove(Node*& pTarget)
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

#endif //SINGLY_LINKED_LIST_H