## Introduction to Algorithms



This is a revision of the basic data structures and algorithms based on but not only on the Introduction to Algorithms.

Language: C++



Here is the catalog for all the documents.

| File Name              | Description                              | Last Edit Time |
| ---------------------- | ---------------------------------------- | -------------- |
| Hash.cpp               | Double hashing                           | 12/31/2017     |
| Heap.h                 | Binary max heap                          | 12/29/2017     |
| Heap.cpp               | Binary max heap                          | 12/29/2017     |
| RBTree.h               | Red black tree                           | 01/03/2018     |
| RBTree.cpp             | Red black tree                           | 01/03/2018     |
| SortingAlgorithm_1.cpp | Bubble, Selection, Insertion sort. O(n^2) | 12/27/2017     |
| SortingAlgorithm_2.cpp | Quick sort, Merge sort. O(NlogN)         | 12/27/2017     |
| SortingAlgorithm_3.cpp | Radix sort, Bucket sort. O(n)            | 12/27/2017     |
| TreeNode.h             | Binary search tree                       | 12/28/2017     |
| TreeNode.cpp           | Binary search tree                       | 12/28/2017     |



##Notice

**Date**: 2018/01/03

In the red black tree, pay attention to the the leaf node, which is nil in fact. They are defined to be the black node. If you didn't define the leaf node, there will be problem in the implement of the red black tree.

I don't define the leaf node in the beginning and it later turns out that I am using a variation whose value is NULL to be the parameter of rotation without noticing.