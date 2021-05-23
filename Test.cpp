#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <random>
using namespace std;

#include "doctest.h"
#include "BinaryTree.hpp"

using namespace ariel;

TEST_CASE("BinaryTree declaration")// 3 tests
{
    CHECK_NOTHROW(BinaryTree <int> tree_of_ints);
    CHECK_NOTHROW(BinaryTree < double > tree_of_doubles);
    CHECK_NOTHROW(BinaryTree < string > tree_of_string);
}

TEST_CASE("BinaryTree initialization") { //18 tests
    srand(time(0));
    //check if template works for different data types
    BinaryTree <int> tree_of_ints;
    BinaryTree < double > tree_of_doubles;
    BinaryTree < string > tree_of_string;

    // int tree
    // initialize tree
    int parent = rand();
    int leftChild = rand();
    int rightChild = rand();

    CHECK_NOTHROW(tree_of_ints.add_root(0));
    CHECK_NOTHROW(tree_of_ints.add_root(parent));
    CHECK_NOTHROW(tree_of_ints.add_left(parent, leftChild));
    CHECK_NOTHROW(tree_of_ints.add_right(parent, rightChild));
    CHECK_NOTHROW(tree_of_ints.add_left(leftChild, rand()));
    CHECK_NOTHROW(tree_of_ints.add_right(rightChild, rand()));

    CHECK_NOTHROW(cout << tree_of_ints << endl);

    // double tree

    double dParent = 0.0;
    double dLeftChild = 1.2;
    double dRightChild = -3.54;

    CHECK_NOTHROW(tree_of_doubles.add_root(dParent));
    CHECK_NOTHROW(tree_of_doubles.add_left(dParent, dLeftChild));
    CHECK_NOTHROW(tree_of_doubles.add_right(dParent, dRightChild));
    CHECK_NOTHROW(tree_of_doubles.add_left(dLeftChild, 13.2));
    CHECK_NOTHROW(tree_of_doubles.add_right(dRightChild, 2.0));

    CHECK_NOTHROW(cout << tree_of_doubles << endl);

    // string tree

    string strParent = "parent";
    string strLeftChild = "leftChild";
    string strRightChild = "rightChild";

    CHECK_NOTHROW(tree_of_string.add_root(strParent));
    CHECK_NOTHROW(tree_of_string.add_left(strParent, strLeftChild));
    CHECK_NOTHROW(tree_of_string.add_right(strParent, strRightChild));
    CHECK_NOTHROW(tree_of_string.add_left(strLeftChild, "grandson"));
    CHECK_NOTHROW(tree_of_string.add_right(strRightChild, "granddaughter"));

    CHECK_NOTHROW(cout << tree_of_string << endl);

}

TEST_CASE("Iterator"){ //21 test
    BinaryTree < int > tree;
    tree.add_root(0)
            .add_left(0, 1)
            .add_left(1, 3)
            .add_left(1, 4)
            .add_right(0, 2)
            .add_right(2, 5)
            .add_right(2, 6)
            .add_left(6, 7);


    BinaryTree<int>::Iterator preorder_itr;
    preorder_itr = tree.begin_preorder();
    while(preorder_itr!= tree.end_preorder()){
        CHECK_NOTHROW(preorder_itr++);
    }

    BinaryTree<int>::Iterator inorder_itr = tree.begin_inorder();
    while(inorder_itr!= tree.end_inorder()){
        CHECK_NOTHROW(inorder_itr++);
    }

    BinaryTree<int>::Iterator postorder_itr = tree.begin_postorder();
    while(postorder_itr!= tree.end_postorder()){
        CHECK_NOTHROW(postorder_itr++);
    }
}

TEST_CASE("Tree Traversals (Inorder, Preorder and Postorder)"){ // 21 tests
    BinaryTree < int > tree;
    tree.add_root(1)
            .add_left(1, 2)
            .add_left(2, 4)
            .add_right(2, 5)
            .add_right(1, 3)
            .add_left(3, 6)
            .add_right(3, 7);

    /*
     *                   (1)
     *                 /     \
     *               /         \
     *            (2)           (3)
     *           /   \         /   \
     *          /     \       /     \
     *        (4)     (5)   (6)     (7)
     *
     *
     *        inorder   :=  4 2 5 1 6 3 7
     *        preorder  :=  1 2 4 5 3 6 7
     *        postorder :=  7 6 3 5 4 2 1
     *
     */

    int inorder[] = {4,2,5,1,6,3,7};
    int preorder[] = {1,2,4,5,3,6,7};
    int postorder[] = {7,6,3,5,4,2,1};
    BinaryTree<int>::Iterator itr;
    int i = 0;
    for(itr = tree.begin_inorder(); itr != tree.end_inorder(); itr++, i++){
        CHECK_EQ(*itr, inorder[i]);
    }

    i = 0;
    for(itr = tree.begin_preorder(); itr != tree.end_preorder(); itr++, i++){
                CHECK_EQ(*itr, preorder[i]);
    }

    i = 0;
    for(itr = tree.begin_postorder(); itr != tree.end_postorder(); itr++, i++){
                CHECK_EQ(*itr, postorder[i]);
    }
}