// Task 7: Template-based Binary Search Tree
#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <functional>

template <typename T>
class BST {
    struct Node {
        T data;
        Node* left;
        Node* right;
        explicit Node(const T& v) : data(v), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;
    size_t count = 0;

    // ---- recursive helpers ----
    Node* insert(Node* n, const T& v, bool& inserted) {
        if (!n) { inserted = true; return new Node(v); }
        if (v < n->data) n->left = insert(n->left, v, inserted);
        else if (n->data < v) n->right = insert(n->right, v, inserted);
        return n;                                   // duplicates ignored
    }
    bool search(Node* n, const T& v) const {
        if (!n) return false;
        if (v < n->data) return search(n->left, v);
        if (n->data < v) return search(n->right, v);
        return true;
    }
    Node* minNode(Node* n) const { while (n && n->left) n = n->left; return n; }
    Node* remove(Node* n, const T& v, bool& removed) {
        if (!n) return nullptr;
        if (v < n->data) n->left = remove(n->left, v, removed);
        else if (n->data < v) n->right = remove(n->right, v, removed);
        else {
            removed = true;
            if (!n->left) { Node* r = n->right; delete n; return r; }       // 0 or 1 child
            if (!n->right) { Node* l = n->left; delete n; return l; }
            Node* succ = minNode(n->right);                                 // 2 children
            n->data = succ->data;
            bool dummy = false;
            n->right = remove(n->right, succ->data, dummy);
        }
        return n;
    }
    void inorder(Node* n, const std::function<void(const T&)>& f) const {
        if (!n) return;
        inorder(n->left, f);
        f(n->data);
        inorder(n->right, f);
    }
    void preorder(Node* n, const std::function<void(const T&)>& f) const {
        if (!n) return;
        f(n->data);
        preorder(n->left, f);
        preorder(n->right, f);
    }
    void postorder(Node* n, const std::function<void(const T&)>& f) const {
        if (!n) return;
        postorder(n->left, f);
        postorder(n->right, f);
        f(n->data);
    }
    int height(Node* n) const {
        if (!n) return 0;
        int l = height(n->left), r = height(n->right);
        return 1 + (l > r ? l : r);
    }
    void destroy(Node* n) {                         // post-order delete -> no leaks
        if (!n) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

public:
    BST() = default;
    ~BST() { destroy(root); }
    BST(const BST&) = delete;                       // prevent shallow copies / double free
    BST& operator=(const BST&) = delete;

    bool insert(const T& v) { bool ins = false; root = insert(root, v, ins); if (ins) count++; return ins; }
    bool search(const T& v) const { return search(root, v); }
    bool remove(const T& v) { bool rem = false; root = remove(root, v, rem); if (rem) count--; return rem; }
    size_t size() const { return count; }
    bool empty() const { return count == 0; }
    int height() const { return height(root); }

    void inOrder(const std::function<void(const T&)>& f) const { inorder(root, f); }
    void preOrder(const std::function<void(const T&)>& f) const { preorder(root, f); }
    void postOrder(const std::function<void(const T&)>& f) const { postorder(root, f); }

    void printInOrder() const { inOrder([](const T& x) { std::cout << x << ' '; }); std::cout << '\n'; }
    void printPreOrder() const { preOrder([](const T& x) { std::cout << x << ' '; }); std::cout << '\n'; }
    void printPostOrder() const { postOrder([](const T& x) { std::cout << x << ' '; }); std::cout << '\n'; }
};

#endif
