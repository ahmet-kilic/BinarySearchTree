#include <iostream>

#include "BST.hpp"

int main() {

    // Testing BSTNode ...
    std::cout << "Testing BSTNode ..." << std::endl;

    BSTNode<int> node(11, NULL, NULL);

    std::cout << "node : " << node << std::endl;

    // Testing BST ...
    std::cout << "Testing BST ..." << std::endl;

    BST<int> tree;
    tree.insert(10);
    tree.insert(15);
    tree.insert(5);
    tree.insert(13);

    tree.remove(13);

    BST<int> tree1;

    tree1 = tree;

    tree.remove(10);
    tree1.remove(15);
    tree.printInorder();
    tree1.printInorder();

    return 0;
}
