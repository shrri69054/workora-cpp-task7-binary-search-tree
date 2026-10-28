# Task 7 – Template Binary Search Tree (C++)

A generic, pointer-based BST written from scratch (`BST<T>`), with an interactive demo.

## Features
- `insert`, `search`, `remove` (leaf, one-child and two-child cases using in-order successor)
- In-order, pre-order, post-order traversals (recursive; accept any callback or print directly)
- `size()`, `height()`, `empty()`
- Duplicates are ignored
- **Memory safety:** destructor deletes every node (post-order); copy constructor/assignment are
  deleted to prevent double-free

## Works with any type that supports `<`
The demo uses `BST<int>` and `BST<std::string>`.

## Build & Run
```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o bst
./bst
```
Optional leak check:
```bash
g++ -std=c++17 -g -fsanitize=address,undefined main.cpp -o bst_check && ./bst_check
```

## Files
| File | Purpose |
|------|---------|
| `bst.hpp` | Template BST implementation (header-only) |
| `main.cpp` | Interactive menu + automatic demo |
| `sample_output.txt` | Output log of the automatic demo |
