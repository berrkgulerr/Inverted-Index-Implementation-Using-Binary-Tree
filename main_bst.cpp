#include <iostream>

#include "BST.hpp"

int main() {
    BST<int> tree;
    tree.insert(10);
    tree.insert(6);
    tree.insert(14);
    tree.insert(5);
    tree.insert(7);
    tree.insert(13);
    tree.insert(15);
    tree.printInorder();
    tree.remove(10);
    tree.printInorder();
    tree.remove(13);
    tree.printInorder();
}
