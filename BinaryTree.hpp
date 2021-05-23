//
// Created by user on 23/05/2021.
//

#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

using std::ostream;

namespace ariel
{
    template<typename T>

    class BinaryTree
    {
    private:
        struct node{
            T value;
            node *rightChild;
            node *leftChild;
            node *parent;
        };
        node *root;
        int treeSize;

    public:
        BinaryTree(){}
        ~BinaryTree(){}

        class Iterator {

        private:
            node* _current;

        public:

            Iterator(node* ptr = nullptr): _current(ptr) {}

            T& operator*() const {
                //return *_current;
                return _current->value;
            }

            T* operator->() const {
                return &(_current->value);
            }

            // ++i;
            Iterator& operator++() {
                //++_current;
                _current = _current->leftChild;
                return *this;
            }

            // i++;
            const Iterator operator++(int) {
                Iterator tmp= *this;
                _current= _current->leftChild;
                return tmp;
            }

            bool operator==(const Iterator& rhs) const {
                return _current == rhs._current;
            }

            bool operator!=(const Iterator& rhs) const {
                return _current != rhs._current;
            }
        }; 

        BinaryTree<T> add_root(T val){
            return *this;
        }

        BinaryTree<T> add_left(T val, T parent){
            return *this;
        }

        BinaryTree<T> add_right(T val, T parent){
            return *this;
        }

        Iterator begin_preorder(){
            return Iterator{root};
        }

        Iterator end_preorder(){
            return Iterator{root};
        }

        Iterator begin_inorder(){
            return Iterator{root};
        }

        Iterator end_inorder(){
            return Iterator{root};
        }

        Iterator begin_postorder(){
            return Iterator{root};
        }

        Iterator end_postorder(){
            return Iterator{root};
        }

        Iterator begin(){
            return Iterator{root};
        }

        Iterator end(){
            return Iterator{root};
        }

        friend ostream &operator<<(ostream &out, const BinaryTree<T> &BT){
            return out;
        }

    };
}
