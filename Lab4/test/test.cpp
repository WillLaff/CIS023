// 16 08 24 04 12 20 28 02 06 10 14 18 22 26 30 01 03 05 07 09 11 13 15 17 19 21 23 25 27 29 31 -999
#include <iostream>
#include "binarySearchTreeType.h"
using namespace std;
int main() {
    binarySearchTreeType<int> T1, T2, T3, T4, T5;
    int num;
    cout << "Enter integers ending with -999" << endl;
    cin >> num;
    while (num != -999) {
        T1.insert(num);
        cin >> num;
    }
    cout << "\ntree1 nodes in inorder: ";
    T1.inorderTraversal();
    cout << "\n\ntree1 nodes in postorder: ";
    T1.postorderTraversal(T2); //Also inserts
    cout << "\n\ntree2 nodes in preorder: ";
    T2.preorderTraversal(T3); //Also inserts
    cout << "\n\ntree3 nodes in inorder: ";
    T3.inorderTraversal();

    cout << endl << "tree1 height: " << T1.treeHeight() << endl;
    cout << "tree1 leaves: " << T1.treeLeavesCount() << endl;
    cout << "tree2 height: " << T2.treeHeight() << endl;
    cout << "tree2 leaves: " << T2.treeLeavesCount() << endl;
    cout << "tree3 height: " << T3.treeHeight() << endl;
    cout << "tree3 leaves: " << T3.treeLeavesCount() << "\n\n\n";

    cout << "swapSubtree for tree3" << endl;
    T3.swapSubtrees();
    cout << "tree3 nodes in inorder: ";
    T3.inorderTraversal();
    cout << endl;
    cout << "tree3 nodes in preorder: ";
    T3.preorderTraversal(T4);
    cout << endl;
    cout << "tree3 nodes in postorder: ";
    T3.postorderTraversal(T5);
    cout << endl;

    return 0;
}