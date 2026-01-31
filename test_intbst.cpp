#include "intbst.h"
#include <iostream>
using namespace std;

int main() {
    IntBST tree;

    cout << "Testing empty tree:" << endl;
    cout << "  sum: " << tree.sum() << endl;
    cout << "  count: " << tree.count() << endl;
    cout << "  contains 5? " << (tree.contains(5) ? "Y" : "N") << endl;
    cout << "  in-order: ";
    tree.printInOrder();
    cout << endl;

    cout << "\nInserting values: 50, 25, 75, 10, 30, 60, 80" << endl;
    tree.insert(50);
    tree.insert(25);
    tree.insert(75);
    tree.insert(10);
    tree.insert(30);
    tree.insert(60);
    tree.insert(80);

    cout << "\nTesting tree after inserts:" << endl;
    cout << "  pre-order: ";
    tree.printPreOrder();
    cout << endl;
    cout << "  in-order: ";
    tree.printInOrder();
    cout << endl;
    cout << "  post-order: ";
    tree.printPostOrder();
    cout << endl;
    cout << "  sum: " << tree.sum() << endl;
    cout << "  count: " << tree.count() << endl;

    cout << "\nTesting contains:" << endl;
    cout << "  contains 50? " << (tree.contains(50) ? "Y" : "N") << endl;
    cout << "  contains 25? " << (tree.contains(25) ? "Y" : "N") << endl;
    cout << "  contains 99? " << (tree.contains(99) ? "Y" : "N") << endl;
    cout << "  contains 10? " << (tree.contains(10) ? "Y" : "N") << endl;

    cout << "\nTesting predecessor:" << endl;
    cout << "  predecessor of 50: " << tree.getPredecessor(50) << endl;
    cout << "  predecessor of 25: " << tree.getPredecessor(25) << endl;
    cout << "  predecessor of 10: " << tree.getPredecessor(10) << endl;
    cout << "  predecessor of 80: " << tree.getPredecessor(80) << endl;

    cout << "\nTesting successor:" << endl;
    cout << "  successor of 50: " << tree.getSuccessor(50) << endl;
    cout << "  successor of 25: " << tree.getSuccessor(25) << endl;
    cout << "  successor of 80: " << tree.getSuccessor(80) << endl;
    cout << "  successor of 10: " << tree.getSuccessor(10) << endl;

    cout << "\nTesting duplicate insert:" << endl;
    cout << "  insert 50 again: " << (tree.insert(50) ? "success" : "failed (duplicate)") << endl;

    cout << "\nTesting remove (leaf node 10):" << endl;
    tree.remove(10);
    cout << "  in-order: ";
    tree.printInOrder();
    cout << endl;
    cout << "  contains 10? " << (tree.contains(10) ? "Y" : "N") << endl;

    cout << "\nTesting remove (node with one child 25):" << endl;
    tree.remove(25);
    cout << "  in-order: ";
    tree.printInOrder();
    cout << endl;

    cout << "\nTesting remove (node with two children 50):" << endl;
    tree.remove(50);
    cout << "  in-order: ";
    tree.printInOrder();
    cout << endl;

    cout << "\nFinal tree state:" << endl;
    cout << "  pre-order: ";
    tree.printPreOrder();
    cout << endl;
    cout << "  count: " << tree.count() << endl;
    cout << "  sum: " << tree.sum() << endl;

    return 0;
}
