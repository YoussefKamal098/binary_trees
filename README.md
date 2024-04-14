# Binary Trees

## Table of the Contents
- [Binary Trees](#binary-trees)
	- [Table of the Contents](#table-of-the-contents)
	- [Binary Trees (General)](#binary-trees-general)
		- [Overview](#overview)
		- [Key concepts and operations](#key-concepts-and-operations)
	- [Binary Search Trees (BST)](#binary-search-trees-bst)
		- [Overview](#overview-1)
		- [Key features](#key-features)
		- [Time Complexity](#time-complexity)
		- [Applications](#applications)
	- [AVL Trees](#avl-trees)
		- [Overview](#overview-2)
		- [Key features](#key-features-1)
		- [Time Complexity](#time-complexity-1)
		- [Applications](#applications-1)
	- [Heap Trees (Max-heap - Min-heap)](#heap-trees-max-heap---min-heap)
		- [Overview](#overview-3)
		- [Key features](#key-features-2)
		- [Time Complexity](#time-complexity-2)
		- [Applications](#applications-2)
	- [Max Heap](#max-heap)
		- [Overview](#overview-4)
		- [Key features](#key-features-3)

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

Certainly! Here's an overview of the time complexity for various operations on binary trees, including average, best, and worst-case scenarios:


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

   - `Efficient searching`: BSTs provide logarithmic time complexity for searching operations, making them suitable for implementing data structures like sets and dictionaries.
   - `Ordered traversal`: BSTs support in-order traversal, which allows elements to be visited in sorted order, making them useful for implementing iterators and generating sorted outputs.
   - `Symbol tables`: BSTs are often used to implement symbol tables in compilers, interpreters, and database systems.


## AVL Trees

### Overview
AVL trees are self-balancing binary search trees in which the heights of the two child subtrees of any node differ by at most one. This balancing property ensures that the height of the tree remains logarithmic, leading to efficient search, insertion, and deletion operations.

### Key features
- **Balancing Factor:** The difference in height between the left and right subtrees of a node is called the balancing factor. AVL trees use rotation operations to rebalance the tree when necessary to maintain the balancing factor.
- **Rotation Operations:** AVL trees employ rotation operations such as left rotation, right rotation, left-right rotation, and right-left rotation to restore balance after insertion or deletion.
- **Self-Balancing:** AVL trees automatically adjust their structure to ensure that the tree remains balanced, optimizing performance for search and other operations.

Certainly! Here's an overview of the time complexity for various operations on binary trees, including average, best, and worst-case scenarios:


### Time Complexity

- **Average Case:**
  - `Search`: O(log n)
  - `Insertion`: O(log n)
  - `Deletion`: O(log n)
  - `Traversal`: O(n)

- **Worst Case:**
  - Same as average case because AVL trees are self-balancing, preventing worst-case scenarios like those in unbalanced binary search trees.


### Applications

   - `Database indexing`: AVL trees are commonly used in database systems for indexing large datasets, enabling fast retrieval of records based on keys.
   - `Balanced storage`: AVL trees ensure that operations such as searching, insertion, and deletion have logarithmic time complexity, making them suitable for scenarios where balanced access to data is essential.
   - `Self-balancing data structures`: AVL trees serve as a foundational concept for understanding self-balancing binary search trees, which are crucial for maintaining efficient data structures in various applications.


## Heap Trees (Max-heap - Min-heap)

### Overview
Heap trees are complete binary trees that satisfy the heap property. In a max heap, every parent node has a value greater than or equal to the values of its children. In a min heap, every parent node has a value less than or equal to the values of its children.

### Key features
- **Heap Property:** The max heap property states that every parent node must have a value greater than or equal to the values of its children. The min heap property is the opposite, with every parent node having a value less than or equal to the values of its children.
- **Insertion:** When inserting a new node into a heap, it is typically added at the bottom level and then "bubbled up" (or "percolated up") to its correct position to maintain the heap property.
- **Extraction:** Extracting the root node of a heap (which is either the maximum or minimum value depending on the heap type) involves removing the root node and then restoring the heap property by "bubbling down" (or "percolating down") the new root value to its correct position.

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
   - `Graph algorithms`: Heap trees are used in graph algorithms such as Dijkstra's algorithm and Prim's algorithm for finding shortest paths and minimum spanning trees, respectively.
   - `Task scheduling`: Heap trees can be employed in task scheduling algorithms, where tasks are scheduled based on their priority or other criteria represented by keys.

## Max Heap

### Overview
A max heap is a complete binary tree in which every parent node has a value greater than or equal to the values of its children. The root node contains the maximum value in the heap.

### Key features
- `Max Heap Property:` In a max heap, every parent node has a value greater than or equal to the values of its children.
- `Insertion:` When inserting a new node into a max heap, it is added at the bottom level of the tree and then "bubbled up" to its correct position by swapping it with its parent as needed to maintain the max heap property.
- `Extraction:` Extracting the maximum value from a max heap involves removing the root node (which contains the maximum value) and then restoring the max heap property by "bubbling down" the new root value to its correct position.

These are the essential concepts and operations associated with binary trees, BSTs, AVL trees, and heap trees, along with specific details for max heaps. Each type of tree has its unique characteristics and use cases

, making them suitable for different scenarios based on their properties and performance characteristics.