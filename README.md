<h1>Binary Trees</h1>

<h2> Table of the Contents </h2>

- [Binary Trees (General)](#binary-trees-general)
	- [Overview](#overview)
	- [Key concepts and operations](#key-concepts-and-operations)
- [Binary Search Trees (BST)](#binary-search-trees-bst)
	- [Overview](#overview-1)
	- [Key features](#key-features)
	- [Time Complexity](#time-complexity)
	- [Applications](#applications)
	- [Advantages](#advantages)
	- [Disadvantages](#disadvantages)
- [AVL Trees](#avl-trees)
	- [Overview](#overview-2)
	- [Key features](#key-features-1)
	- [Time Complexity](#time-complexity-1)
	- [Applications](#applications-1)
	- [Advantages](#advantages-1)
	- [Disadvantages](#disadvantages-1)
- [Heap Trees (Max-heap - Min-heap)](#heap-trees-max-heap---min-heap)
	- [Overview](#overview-3)
	- [Key features](#key-features-2)
	- [Time Complexity](#time-complexity-2)
	- [Applications](#applications-2)
	- [Advantages](#advantages-2)
	- [Disadvantages](#disadvantages-2)
- [Conclusion](#conclusion)

## Binary Trees (General)
### Overview
Binary trees are hierarchical data structures composed of nodes, where each node has at most two children, referred to as the left child and the right child. The topmost node of the tree is called the root. Nodes that do not have any children are called leaf nodes. Binary trees are used in various applications, including representing hierarchical data such as directory structures, expression parsing, and more.

### Key concepts and operations
- `Node`:Each element in a binary tree is called a node. Nodes contain data and references (or pointers) to their left and right children.
- `Root`: The topmost node of the tree.
- `Parent, Child, Sibling:` Nodes in a binary tree have a parent-child relationship. Nodes with the same parent are called siblings.
- `Leaf Node:` Nodes that do not have any children.
- `Traversal:` Techniques for visiting all nodes in a tree in a specific order, such as in-order, pre-order, and post-order traversal.
- `Search:` Searching for a specific node or value in the tree.
- `Insertion and Deletion:` Adding and removing nodes from the tree while maintaining the binary tree properties.
- `Balanced vs. Unbalanced Trees:` Balanced trees have approximately the same number of nodes on the left and right subtrees, leading to more efficient operations.


## Binary Search Trees (BST)

### Overview
A binary search tree is a special type of binary tree in which the value of each node is greater than all values in its left subtree and less than all values in its right subtree. This property allows for efficient search, insertion, and deletion operations.

### Key features
- `Search Operation:` Binary search trees support efficient search operations by recursively traversing the tree based on the comparison of values.
- `Insertion:` When inserting a new node, the tree maintains the binary search tree property by finding the appropriate position based on the node's value.
- `Deletion:` Deleting a node requires maintaining the binary search tree property while handling different cases such as nodes with zero, one, or two children.

### Time Complexity

- **Average Case:**
  - `Search`: (in a balanced tree): O(log n)
  - `Insertion`: (in a balanced tree): O(log n)
  - `Deletion`: (in a balanced tree): O(log n)
  - `Traversal`: (in-order, pre-order, post-order): O(n)

- **Worst Case:**
  - `Search`: O(n) (when the tree is unbalanced and degenerates into a linked list)
  - `Insertion`: O(n) (when the tree is unbalanced and degenerates into a linked list)
  - `Deletion`: O(n) (when the tree is unbalanced and degenerates into a linked list)
  - `Traversal`: O(n)

### Applications

- `Database Indexing`: BSTs are commonly used in databases to store and index records. They provide efficient searching, insertion, and deletion operations, making data retrieval fast and reliable.
- `Symbol Tables`: BSTs are employed in compilers, interpreters, and symbol tables for storing identifiers (such as variables and functions) and quickly searching for them during compilation or interpretation processes.
- `File System Structure`: File systems often use BSTs to organize directory structures. Each directory entry can be stored in a BST, allowing for efficient searching and traversal of directories.

### Advantages
- `Efficient Searching`: BSTs offer efficient searching operations with a time complexity of O(log n) on average, making them suitable for applications requiring fast retrieval of data.
- `Ordered Structure`: BSTs maintain a sorted order of elements, facilitating operations like finding minimum and maximum values, as well as range queries.
- `Flexible Insertion and Deletion`: Insertion and deletion operations in BSTs are relatively simple and efficient, especially in balanced trees, providing flexibility in maintaining and updating data.
- `Simple Implementation`: BSTs are relatively easy to implement and understand, making them accessible for various applications and programming scenarios.

### Disadvantages
- `Unbalanced Trees`: In some cases, BSTs may become unbalanced due to uneven distribution of elements, resulting in degradation of performance for search, insert, and delete operations.
-  `Performance Degradation`: In the worst-case scenario, when the tree is highly unbalanced, the time complexity of operations can degrade to O(n), nullifying the advantages of BSTs.
- `Sensitive to Input Order`: The performance of BSTs is sensitive to the order in which elements are inserted, potentially leading to highly unbalanced trees if elements are inserted in sorted order.


## AVL Trees

### Overview
AVL trees are self-balancing binary search trees in which the heights of the two child subtrees of any node differ by at most one. This balancing property ensures that the height of the tree remains logarithmic, leading to efficient search, insertion, and deletion operations.

### Key features
- `Balancing Factor:` The difference in height between the left and right subtrees of a node is called the balancing factor. AVL trees use rotation operations to rebalance the tree when necessary to maintain the balancing factor.
- `Rotation Operations:` AVL trees employ rotation operations such as left rotation, right rotation, left-right rotation, and right-left rotation to restore balance after insertion or deletion.
- `Self-Balancing:` AVL trees automatically adjust their structure to ensure that the tree remains balanced, optimizing performance for search and other operations.

### Time Complexity

- **Average Case:**
  - `Search`: O(log n)
  - `Insertion`: O(log n)
  - `Deletion`: O(log n)
  - `Traversal`: O(n)

- **Worst Case:**
  - Same as average case because AVL trees are self-balancing, preventing worst-case scenarios like those in unbalanced binary search trees.


### Applications

- `Database Indexing and Search Optimization`: AVL trees, being self-balancing, ensure that search operations in databases remain efficient even as the dataset grows. They are used in scenarios where frequent updates to the database are expected, maintaining optimal performance.
 - `Network Routing Algorithms`: In computer networks, AVL trees are used in routing algorithms to maintain balanced routing tables. This ensures that packets are routed efficiently through the network without any single path becoming congested.
- `Geospatial Data Structures`: AVL trees are employed in geographic information systems (GIS) for storing and querying spatial data efficiently. They can be used to represent and search for points, lines, and polygons in geographic space.

### Advantages 
-  `Balanced Structure`: AVL Trees are self-balancing binary search trees, ensuring that the height of the tree remains logarithmic, resulting in consistent time complexity for operations (O(log n)).
-  `Improved Performance`: AVL Trees offer improved performance compared to unbalanced BSTs, especially for scenarios where frequent insertions and deletions occur, as the tree automatically maintains balance.
- `Guaranteed Time Complexity`: With AVL Trees, the worst-case time complexity for search, insert, and delete operations remains O(log n), providing predictable and consistent performance.

### Disadvantages
 - `Complex Implementation`: Implementing AVL Trees requires additional logic to maintain balance during insertion and deletion, increasing the complexity of the code compared to regular BSTs.
 - `Overhead`: AVL Trees may incur additional overhead in terms of memory and computational resources due to the extra bookkeeping required to maintain balance, although this overhead is generally minimal.
- `Potentially Slower Operations`: While AVL Trees provide guaranteed logarithmic time complexity, the constant factors involved in rebalancing operations may result in slightly slower performance compared to simpler data structures in some scenarios.


## Heap Trees (Max-heap - Min-heap)

### Overview
Heap trees are complete binary trees that satisfy the heap property. In a max heap, every parent node has a value greater than or equal to the values of its children. In a min heap, every parent node has a value less than or equal to the values of its children.

### Key features
- `Heap Property:` The max heap property states that every parent node must have a value greater than or equal to the values of its children. The min heap property is the opposite, with every parent node having a value less than or equal to the values of its children.
- `Insertion:` When inserting a new node into a heap, it is typically added at the bottom level and then "bubbled up" (or "percolated up") to its correct position to maintain the heap property.
- `Extraction:` Extracting the root node of a heap (which is either the maximum or minimum value depending on the heap type) involves removing the root node and then restoring the heap property by "bubbling down" (or "percolating down") the new root value to its correct position.

### Time Complexity

- **Average Case:**
  - `Insertion`: O(log n)
  - `Extraction (root)`: O(log n)
  - `Searching`: O(n) (searching for an arbitrary value)

- **Worst Case:**
  - `Insertion`: O(log n) (when inserting an element at the bottom level and percolating up)
  - `Extraction`: O(log n) (when extracting the root and percolating down)
  - `Searching`: O(n) (when searching for an arbitrary value in the worst case)
  
### Applications
   - `Priority queues`: Heap trees, particularly binary heaps, are commonly used to implement priority queues, where elements are inserted with associated priorities and extracted in order of priority.
   - `Memory Management`: Heap trees are utilized in memory allocation algorithms, such as the buddy system and malloc/free implementations. They help manage dynamic memory allocation efficiently, ensuring that memory requests are serviced promptly and memory fragmentation is minimized.
   - `Graph algorithms`: Heap trees are used in graph algorithms such as Dijkstra's algorithm and Prim's algorithm for finding shortest paths and minimum spanning trees, respectively.
   - `Task scheduling`: Heap trees can be employed in task scheduling algorithms, where tasks are scheduled based on their priority or other criteria represented by keys.
  

### Advantages
- `Efficient Priority Queue`: Heap Trees are ideal for implementing priority queues, offering efficient insertion, deletion, and retrieval of the highest (or lowest) priority element with a time complexity of O(log n).
- `Compact Representation`: Heap Trees can be represented using arrays, resulting in a compact data structure that requires less memory overhead compared to linked structures like AVL Trees.
- `Simple Implementation`: The basic operations of heapify and heap extract are relatively simple to implement, making Heap Trees suitable for scenarios where simplicity and efficiency are key considerations.

### Disadvantages 
- `Lack of Order`: Unlike BSTs, Heap Trees do not maintain any specific order among elements, which limits their applicability for operations requiring sorted data.
- `Limited Flexibility`: Heap Trees are primarily designed for priority queue operations and do not support other common binary search tree operations such as searching for specific values or range queries.
- `Inefficient Update Operations`: Updating elements in a Heap Tree (e.g., changing the priority of an existing element) typically requires deletion followed by reinsertion, resulting in less efficient update operations compared to AVL Trees.

## Conclusion
These are the essential concepts and operations associated with binary trees, BSTs, AVL trees, and heap trees, along with specific details for max heaps. Each type of tree has its unique characteristics and use cases, making them suitable for different scenarios based on their properties and performance characteristics.