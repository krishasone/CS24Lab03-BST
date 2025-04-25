// testbst.cpp
// Tests intbst.cpp for CS 24 lab

#include "intbst.h"

#include <iostream>
using namespace std;

int getTest();

// creates two trees (one of which is empty),
// and does some simple tests of tree methods
int main() {

    IntBST bst1, bst2;

    // insert data to bst1
    bst1.insert(1000);
    bst1.insert(15);
    bst1.insert(12);
    bst1.insert(380);
    bst1.insert(19);
    bst1.insert(10);
    bst1.insert(100);
    bst1.insert(50);
    bst1.insert(1500);
    bst1.insert(2);
    bst1.insert(33);
    bst1.insert(77);
    bst1.insert(180);
    
    
    // let user choose one or all tests
    bool all = true;
    int testnum = getTest();
    if (testnum)
        all = false;

    // print and test methods for bst1
    cout << "BST: " << endl << "  pre-order: ";
    bst1.printPreOrder();
    cout << endl;
    if (all || testnum == 1) {
        cout << "  in-order: ";
        bst1.printInOrder();
        cout << endl;
    }
    if (all || testnum == 2) {
        cout << "  post-order: ";
        bst1.printPostOrder();
        cout << endl;
    }
    if (all || testnum == 3)
        cout << "  sum: " << bst1.sum() << endl;
    if (all || testnum == 4)
        cout << "  count: " << bst1.count() << endl;
    if (all || testnum == 5) {
	cout << "  contains 1500? " <<
            (bst1.contains(1500) ? "Y" : "N") << endl;
	cout << "  contains 50? " <<
            (bst1.contains(50) ? "Y" : "N") << endl;
        cout << "  contains 12? " <<
            (bst1.contains(12) ? "Y" : "N") << endl;
        cout << "  contains 77? " <<
            (bst1.contains(77) ? "Y" : "N") << endl;
        cout << "  contains 180? " <<
            (bst1.contains(180) ? "Y" : "N") << endl;
        cout << "  contains 19? " <<
            (bst1.contains(19) ? "Y" : "N") << endl;
    }
    if(all || testnum == 6){
	cout << "  predecessor of 1500 is: " <<
	    bst1.getPredecessor(1500) << endl;
	cout << "  predecessor of 50 is: " <<
	    bst1.getPredecessor(50) << endl;
	cout << "  predecessor of 12 is: " <<
	    bst1.getPredecessor(12) << endl;
	cout << "  successor of 77 is: " <<
	    bst1.getSuccessor(77) << endl;
	cout << "  successor of 180 is: " <<
	    bst1.getSuccessor(180) << endl;
	cout << "  successor of 19 is: " <<
	    bst1.getSuccessor(19) << endl;
    }
    if(all || testnum == 7) {
	cout << "  removing 1500" << endl;
	bst1.remove(1500);
	cout << "  removing 50" << endl;
	bst1.remove(50);
	cout << "  removing 77" << endl;
	bst1.remove(77);
	cout << "  contains 1500? " <<
            (bst1.contains(1500) ? "Y" : "N") << endl;
	cout << "  contains 4? " <<
	    (bst1.contains(4) ? "Y" : "N") << endl;
        cout << "  contains 77? " <<
            (bst1.contains(77) ? "Y" : "N") << endl;
        cout << "  contains 380? " <<
            (bst1.contains(380) ? "Y" : "N") << endl;
        cout << "  contains 180? " <<
            (bst1.contains(180) ? "Y" : "N") << endl;
        cout << "  contains 50? " <<
            (bst1.contains(50) ? "Y" : "N") << endl;
	cout << "  pre-order: ";
        bst1.printPreOrder();
        cout << endl;
    }

    // test methods for empty bst2
    cout << "Empty BST: " << endl << "  pre-order: ";
    bst2.printPreOrder();
    cout << endl;
    if (all || testnum == 1) {
        cout << "  in-order: ";
        bst2.printInOrder();
        cout << endl;
    }
    if (all || testnum == 2) {
        cout << "  post-order: ";
        bst2.printPostOrder();
        cout << endl;
    }
    if (all || testnum == 3)
        cout << "  sum: " << bst2.sum() << endl;
    if (all || testnum == 4)
        cout << "  count: " << bst2.count() << endl;
    if (all || testnum == 5)
        cout << "  contains 16? " <<
            (bst2.contains(16) ? "Y" : "N") << endl;

    // add tests for optional methods that you attempt to implement
    // but don't do that until after submitting the basic version

    return 0;
}

int getTest() {
    cout << "Choice of tests:\n"
	 << "  0. all tests\n"
	 << "  1. just printInOrder\n"
	 << "  2. just printPostOrder\n"
	 << "  3. just sum\n"
	 << "  4. just count\n"
	 << "  5. just contains\n"
	 << "  6. just predecessor/successor\n"
	 << "  7. just remove\n";
	 
    do {
        int choice;
        cout << "Enter choice:\n";
        cin >> choice;
        if (choice >=0 && choice <= 7)
            return choice;
        cout << "0, 1, 2, 3, 4, 5, 6, or 7 only!\n";
    } while (true);
}
