## 1. Linear Data Structures

- [x] array
    - char array
    - two pointers / sliding window
    - prefix sum
    - intervals
    - bitmap
- [x] vector
- [x] linkedlist
    - [x] singly
    - doubly
    - cycle detection (fast & slow pointer)
    - reversal
- [x] stack
    - monotonic stack
- [x] queue
    - monotonic queue
- [x] hashmap (unordered_map)

## 2. Non-Linear Data Structures

- tree
    - binary tree
    - binary search tree (BST)
- heap / priority queue
    - min / max heap
- graph
    - bfs
    - dfs
    - cycle detection
    - topological sort
    - ss shortest paths
    	- dijkstra
    - disjoint set union

## 3. Algorithms & Paradigms

- sorting
    - bubble
    - insertion
    - selection
    - merge
    - quick
    - counting
- dynamic programming
    - memoization
    - tabulation
- greedy
- recursion
    - backtracking
- math & bitwise
    - sieve of eratosthenes (primes)
    - bitmasking

---

Open, try solve, if cannot, dont look at hint, try breakdown concepts and try seperate codes

5 problems that act as "gateway" problems. Each one covers multiple nodes in your restructured tree.
1. The "Sliding Window" Gateway
Problem: 3. Longest Substring Without Repeating Characters
 * Categories Covered: array (char array), two pointers / sliding window, [x] hashmap.
 * Why: This is the "Hello World" of sliding windows. You use a hashmap (or a simple 128-byte array, which is better for embedded!) to track characters and two pointers to define the window.
2. The "Fast & Slow Pointer" Gateway
Problem: 141. Linked List Cycle
 * Categories Covered: [x] linkedlist, cycle detection, fast & slow pointer.
 * Why: Standard cycle detection. It’s O(1) space—critical for systems like the ESP32 where you can't just allocate a huge hash set to track visited nodes.
3. The "Monotonic Stack" Gateway
Problem: 739. Daily Temperatures
 * Categories Covered: [x] stack, monotonic stack, array.
 * Why: This teaches you how to use a stack to store "pending" information that will be resolved by future data. It’s a very common pattern in high-frequency data processing.
4. The "Graph & BFS/DFS" Gateway
Problem: 200. Number of Islands
 * Categories Covered: graph, bfs, dfs, matrix traversal.
 * Why: You learn how to traverse a 2D grid. This is fundamental for pathfinding and cycle detection. In the interview, you can talk about the stack depth (recursion limit) vs. using an explicit queue for BFS.
5. The "Bitmasking" Gateway (Your Superpower)
Problem: 136. Single Number
 * Categories Covered: math & bitwise, bitmasking, array.
 * Why: This is the classic XOR trick (x \oplus x = 0). It shows how bitwise logic can replace complex data structures (like a hashmap) to achieve O(1) space.