# Data Structures

 Data structures are fundamental concepts in computer science that organize and manage data efficiently. The Standard Template Library (STL) in C++ provides a rich set of data structures and algorithms. Let's explore some of the key data structures provided by the STL in detail:

 + 🌸 `Vector` : A vector is a dynamic array that can change size. It allows random access to elements and provides efficient operations at the end of the sequence.

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);  // Add an element to the end
    vec.pop_back();    // Remove the last element

    for (int i : vec) {
        std::cout << i << " ";
    }
    return 0;
}
```
Key Operations:

    + push_back(): Adds an element at the end.
    + pop_back(): Removes the last element.
    + size(): Returns the number of elements.
    + [] operator: Provides random access.

+ 🌸 `List` : A list is a doubly linked list, allowing efficient insertions and deletions at both ends and in the middle, but it does not support random access.

```cpp
#include <list>
#include <iostream>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    lst.push_back(6);
    lst.push_front(0);

    for (int i : lst) {
        std::cout << i << " ";
    }
    return 0;
}
```
Key Operations:

    + push_back(): Adds an element to the end.
    + push_front(): Adds an element to the beginning.
    + pop_back(): Removes the last element.
    + pop_front(): Removes the first element.
    + insert(): Inserts elements at specific positions.
    + erase(): Removes elements at specific positions.

+ 🌸 `Deque` : A deque (double-ended queue) allows insertion and deletion at both ends with constant time complexity.

```cpp
#include <deque>
#include <iostream>

int main() {
    std::deque<int> dq = {1, 2, 3, 4, 5};
    dq.push_back(6);
    dq.push_front(0);

    for (int i : dq) {
        std::cout << i << " ";
    }
    return 0;
}
```
Key Operations:

    + push_back(): Adds an element to the end.
    + push_front(): Adds an element to the beginning.
    + pop_back(): Removes the last element.
    + pop_front(): Removes the first element.

+ 🌸 `Stack` : A stack is a LIFO (Last In, First Out) data structure. Elements are added and removed from the top of the stack.

```cpp
#include <stack>
#include <iostream>

int main() {
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);

    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}
```
Key Operations:

    + push(): Adds an element to the top.
    + pop(): Removes the top element.
    + top(): Returns the top element.
    + empty(): Checks if the stack is empty.

+ 🌸 `Queue` : A queue is a FIFO (First In, First Out) data structure. Elements are added at the back and removed from the front.

```cpp
#include <queue>
#include <iostream>

int main() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
```
Key Operations:

    + push(): Adds an element to the back.
    + pop(): Removes the front element.
    + front(): Returns the front element.
    + back(): Returns the back element.
    + empty(): Checks if the queue is empty.

Resources : My [notes](https://github.com/florist-notes/alg0rith.math/blob/main/competitive_prog/stl.MD) on STL Data Structures with C++, [geeksforgeeks.org/data-structures/](https://www.geeksforgeeks.org/data-structures/), [cpp-builtin-ds_cheatsheet](https://www.codecademy.com/learn/c-plus-plus-for-programmers/modules/cpp-built-in-data-structures/cheatsheet), [cplusplus.com/data-structures](https://cplusplus.com/doc/tutorial/structures/), @github/[TheAlgorithms_CPlusPlus](https://github.com/TheAlgorithms/C-Plus-Plus), @github/[algorithms&ds](https://github.com/mandliya/algorithms_and_data_structures), [C++ STL](https://www.youtube.com/watch?v=R5BEcvTVZj0&list=PLauivoElc3gh3RCiQA82MDI-gJfXQQVnn).