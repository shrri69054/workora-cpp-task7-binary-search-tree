// Task 7: Interactive demo for the BST template
#include <iostream>
#include <limits>
#include <string>
#include "bst.hpp"
using namespace std;

int readInt(const string& prompt) {
    int v;
    while (true) {
        cout << prompt;
        if (cin >> v) return v;
        if (cin.eof()) exit(0);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [Error] Enter a valid integer.\n";
    }
}

void autoDemo() {
    cout << "\n--- Automatic demo (int tree) ---\n";
    BST<int> t;
    int vals[] = {50, 30, 70, 20, 40, 60, 80, 35, 65};
    for (int v : vals) t.insert(v);
    cout << "Inserted: 50 30 70 20 40 60 80 35 65\n";
    cout << "In-order  : "; t.printInOrder();
    cout << "Pre-order : "; t.printPreOrder();
    cout << "Post-order: "; t.printPostOrder();
    cout << "Size: " << t.size() << ", Height: " << t.height() << "\n";
    cout << "Search 60 -> " << (t.search(60) ? "found" : "not found") << "\n";
    cout << "Search 99 -> " << (t.search(99) ? "found" : "not found") << "\n";
    t.remove(20); t.remove(30); t.remove(50);       // leaf, one-child/two-child, root
    cout << "After deleting 20, 30, 50:\nIn-order  : "; t.printInOrder();

    cout << "\n--- Template check (string tree) ---\n";
    BST<string> s;
    for (string w : {"mango", "apple", "kiwi", "banana", "orange"}) s.insert(w);
    cout << "In-order  : "; s.printInOrder();
}

int main() {
    BST<int> tree;
    while (true) {
        cout << "\n===== BINARY SEARCH TREE =====\n"
             << "1. Insert\n2. Search\n3. Delete\n4. In-order\n5. Pre-order\n6. Post-order\n"
             << "7. Size & height\n8. Run automatic demo\n9. Exit\n";
        int c = readInt("Choice: ");
        switch (c) {
            case 1: cout << (tree.insert(readInt("Value: ")) ? "  Inserted.\n" : "  Duplicate ignored.\n"); break;
            case 2: cout << (tree.search(readInt("Value: ")) ? "  Found.\n" : "  Not found.\n"); break;
            case 3: cout << (tree.remove(readInt("Value: ")) ? "  Deleted.\n" : "  Value not in tree.\n"); break;
            case 4: if (tree.empty()) cout << "  Tree is empty.\n"; else tree.printInOrder(); break;
            case 5: if (tree.empty()) cout << "  Tree is empty.\n"; else tree.printPreOrder(); break;
            case 6: if (tree.empty()) cout << "  Tree is empty.\n"; else tree.printPostOrder(); break;
            case 7: cout << "  Size: " << tree.size() << ", Height: " << tree.height() << "\n"; break;
            case 8: autoDemo(); break;
            case 9: cout << "Tree memory freed automatically by destructor. Goodbye!\n"; return 0;
            default: cout << "  Invalid choice.\n";
        }
    }
}
