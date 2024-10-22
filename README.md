# Algorithm and Data Structure Task #1

## Part 1 - Design a `SinglyLinkedList` class

Design a class `SinglyLinkedList` to represent collection  - singly linked list. Write unit tests for the designed class, at least one test per method.

Please consider what operations can be implemented (it makes sense to implement, is efficient)
for a singly linked list. In particular, whether it is possible to efficiently
implement deletion from the beginning and end of the list.

```c++
template <typename Key, typename Info>
class SinglyLinkedList
{
public:
    SinglyLinkedList();

    SinglyLinkedList(const SinglyLinkedList& src)
    {
        // initialize properly data members
        // probably as in default constructor
        *this = src;
    }

    ~SinglyLinkedList();

    SinglyLinkedList& operator=(const SinglyLinkedList& src);

    unsigned int size() const;
    void push_front(const Key& key, const Info& info);
    // keys are not unique!
    bool pop_front();

    // and the rest of the interface
private:
};
```

## Part 2 – Implement additional function
Write additional (external) function (not methods) and unit tests for them.

```c++
//Function concatenate two collections by moving the elements from the source collections:
// seq1 and seq2 to the target collection seq
template <typename Key, typename Info>
void concatenate(SinglyLinkedList <Key, Info>& seq1, SinglyLinkedList <Key, Info>& seq2,
                unsigned int len1, unsignedint len2, SinglyLinkedList <Key, Info>& seq)
{
    //…
}
```

### Example 1 for concatenate:
#### Parameters:
    seq1={0,1,2,3,4,5,6,7,8,9,10,11,12},
    seq1={20,21,22,23,24,25,26},
    len1=2, len2=3

#### Result:

    seq={0,1,20,21,22,2,3,23,24,25,4,5,26,6,7,8,9,10,11,12}
    seq1={}
    seq2={}

### Example 2 for concatenate:
#### Parameters:
    seq1={0,1,2,3,4},
    seq1={20,21,22},
    len1=2, len2=0
#### Result:
    seq={0,1,2,3,4}
    seq1={}
    seq2={}

### Example 3 for concatenate:
#### Parameters:
    seq1={0,1,2,3,4},
    seq1={20,21,22},
    len1=0, len2=20
#### Result:
    seq={20,21,22}
    seq1={}
    seq2={}

### Example 4 for concatenate:
#### Parameters:
    seq1={0,1,2,3,4},
    seq1={20,21,22},
    len1=0, len2=0
#### Result:
    seq={}
    seq1={}
    seq2={}


## Part 3 - Design a `Stack` class
Design and implement a `Stack` class that internally uses the `SinglyLinkedList` class to store elements.
The class should provide only stack operations. The internal implementation should be hidden (private). The `Stack` class should not inherit from the `SinglyLinkedList` class.
