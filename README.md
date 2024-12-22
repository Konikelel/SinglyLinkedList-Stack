# Project Description: Implementation of `SinglyLinkedList` and `Stack` Data Structures

This project focuses on the design and implementation of a class called `SinglyLinkedList`, which represents a collection of elements arranged in a singly linked structure. Additionally, the project includes the design of a `Stack` class that utilizes the `SinglyLinkedList` for its internal storage, further enhancing the usability of both data structures.

## Designing the `SinglyLinkedList` Class

In the first part of this project, the primary objective is to create a robust class named `SinglyLinkedList`, which acts as a singly linked list. The class is expected to include:

* **Node Structure**: Internally define a `Node` structure that holds key-value pairs (Key and Info) along with a pointer to the next node.

* **Member Functions**: Implement various member functions that allow for dynamic interaction with the linked list, including:
  
  * **Constructors and Destructors**: Properly manage the lifecycle of the list and its nodes.
  
  * `push_front()`: To insert a new element at the front of the list.
  
  * `pop_front()`: To remove and return the first element from the list.
  
  * `size()`: To retrieve the current number of elements in the list.

The design should aim to ensure efficiency and clarity of the `SinglyLinkedList` class, while also laying a solid foundation for the implementation of the `Stack` class.

## Designing the `Stack` Class

The second part of the project is focused on creating a `Stack` class that internally uses the `SinglyLinkedList` to store its elements. The `Stack` class will encapsulate stack-specific operations and maintain the integrity of the underlying linked list.

### Key Features of the `Stack` Class:
* **Member Functions**: Implement methods that adhere to the Last In, First Out (LIFO) principle:
  
  * `push()`: To add an element to the top of the stack.
  
  * `pop()`: To remove the top element from the stack.
  
  * `peek()`: To return the top element without removing it.
  
  * `isEmpty()`: To check if the stack is empty.

The `Stack` class will provide a clear interface for managing its elements while abstracting away the complexity of the underlying `SinglyLinkedList`.

## Implementing Additional Function Templates

In addition to the core data structure implementations, the project will include external function template that offer advanced operations on `SinglyLinkedList` instances:

1. **Concatenate**: A function that merges two singly linked lists, allowing elements from both lists to interleave while clearing the original lists.
