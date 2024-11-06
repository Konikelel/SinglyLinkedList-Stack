#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H


template <typename Key, typename Info>
class SinglyLinkedList
{
public:
    SinglyLinkedList() : head(nullptr), count(0) {}
    SinglyLinkedList(const SinglyLinkedList& src);
    ~SinglyLinkedList();
    
    bool exist(const Key& key, unsigned int occ = 1) const;
    int getPosition(const Key& key, unsigned int occ = 1) const;
    Info& get(const Key& key, unsigned int occ = 1) const;
    bool get(const Key& key, Info& result, unsigned int occ = 1) const;
    Info& getFirst() const;
    bool getFirst(Info& result) const;
    bool insertFront(const Key& key, const Info& info);
    bool insertAfter(const Key& key, const Info& info, const Key& where, unsigned int occ = 1);
    bool removeFront();
    unsigned int removeAll(const Key& key);
    bool remove(const Key& key, unsigned int occ = 1);
    [[nodiscard]] unsigned int size() const;
    [[nodiscard]] bool isEmpty() const;
    bool clear();
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
    unsigned int count; // To optimize function size()

    /*
     * Get node with key of n-th occurrence
     * If found return pointer to element and override pPrevNode with pointer to previous element
     * If not found return nullptr
     */
    Node* getNode(const Key& key, Node*& pPrevNode, unsigned int occ = 1) const;
    Node* getNode(const Key& key, unsigned int occ = 1) const;
    // To have everything in one place: setting count, memory allocation, etc.
    bool removeNode(Node*& pTarget);
    bool insertNode(Node*& pTarget, const Key& key, const Info& info);

    template <typename K, typename I>
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<K, I>& list);
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
Info& SinglyLinkedList<Key, Info>::get(const Key& key, const unsigned int occ) const
{
    Node *pNode = this->getNode(key, occ);
    if (pNode == nullptr)
    {
        throw std::runtime_error("Couldn't get the Node");
    }
    return pNode->info;
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
Info& SinglyLinkedList<Key, Info>::getFirst() const
{
    if (this->isEmpty())
    {
        throw std::runtime_error("Couldn't get first Node");
    }
    return this->head->info;
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
bool SinglyLinkedList<Key, Info>::insertFront(const Key& key, const Info& info)
{
    return this->insertNode(this->head, key, info);
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::insertAfter(const Key& key, const Info& info, const Key& where, const unsigned int occ)
{
    Node *pPrev = this->getNode(where, occ);
    if (pPrev == nullptr)
    {
        return false;
    }
    return this->insertNode(pPrev->next, key, info);
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::removeFront()
{
    return this->removeNode(this->head);
}

template <typename Key, typename Info>
unsigned int SinglyLinkedList<Key, Info>::removeAll(const Key& key)
{
    unsigned int delItemNr = 0;
    for(Node *pPrev = nullptr, *pCurr = this->head; pCurr != nullptr; pCurr = pPrev == nullptr ? this->head : pPrev->next)
    {
        if (pCurr->key == key)
        {
            if(this->removeNode(pPrev == nullptr ? this->head : pPrev->next))
            {
                delItemNr++;
            }
            continue;
        }
        pPrev = pCurr;
    }

    return delItemNr;
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
    return this->count;
}

template <typename Key, typename Info>
[[nodiscard]] bool SinglyLinkedList<Key, Info>::isEmpty() const
{
    return !this->count;
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::clear()
{
    if (this->isEmpty())
    {
        return false;
    }
    for (Node *pCurr; (pCurr = this->head) != nullptr;)
    {
        this->head = this->head->next;
        delete pCurr;
    }
    this->count = 0;
    return true;
}

template <typename Key, typename Info>
void SinglyLinkedList<Key, Info>::extend(const SinglyLinkedList& other)
{
    if (other.isEmpty())
    {
        return;
    }
    // auto cpy(other);
    // last->next = cpy.head;
    // cpy.head = nullptr;
    
    Node *pThisCurr = this->head, *pOtherCurr = other.head;
    if (this->isEmpty())
    {
        this->insertNode(this->head, pOtherCurr->key, pOtherCurr->info);
        pOtherCurr = pOtherCurr->next, pThisCurr = this->head;
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
        this->insertNode(pThisCurr->next, pOtherCurr->key, pOtherCurr->info);
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
    Node *pTemp; // To avoid duplicating of code, encapsulation keeping original function consistent
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
    --this->count;
    return true;
}

template <typename Key, typename Info>
bool SinglyLinkedList<Key, Info>::insertNode(Node*& pTarget, const Key& key, const Info& info)
{
    pTarget = new Node{key, info, pTarget};
    ++this->count;
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

template <typename Key, typename Info>
std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<Key, Info>& list)
{
    for (typename SinglyLinkedList<Key, Info>::Node *pCurr = list.head; pCurr != nullptr; pCurr = pCurr->next)
    {
        os << pCurr->key << ": " << pCurr->info << std::endl;
    }
    return os;  
}

#endif //SINGLY_LINKED_LIST_H