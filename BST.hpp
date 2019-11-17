#ifndef BST_HPP
#define BST_HPP

#include <iostream>

#include "BSTNode.hpp"

template <class T>
class BST {
public: // DO NOT CHANGE THIS PART.
    BST();
    BST(const BST<T> &obj);

    ~BST();

    BSTNode<T> *getRoot();

    void insert(const T &data);
    void remove(const T &data);
    BSTNode<T> *find(const T &data);
    void printInorder();

    BST<T> &operator=(const BST<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    void printInorder(BSTNode<T> *node);
    void deleteBST(BSTNode<T> *&r);
    void copy_helper(BSTNode<T> *&rhs, BSTNode<T> *lhs);
    void insert_helper(BSTNode<T> *&r, T val);
    BSTNode<T> *find_helper(BSTNode<T> *&r, T val);
    void remove_helper(BSTNode<T> *&r, T val);
    T getMin(BSTNode<T> *r);

private: // DO NOT CHANGE THIS PART.
    BSTNode<T> *root;
};

#endif //BST_HPP

template <class T>
BST<T>::BST() {
    /* TODO */
    root = NULL;
}

template <class T>
BST<T>::BST(const BST<T> &obj) {
    /* TODO */
    if(obj.root == NULL)
        root = NULL;
    else
        copy_helper(root, obj.root);
}

template <class T>
BST<T>::~BST() {
    /* TODO */
    deleteBST(root);
}

template <class T>
BSTNode<T> *BST<T>::getRoot() {
    /* TODO */
    return this->root;
}

template <class T>
void BST<T>::insert(const T &data) {
    /* TODO */
    insert_helper(root, data);
}

template <class T>
void BST<T>::remove(const T &data) {
    /* TODO */
    remove_helper(root, data);
}

template <class T>
BSTNode<T> *BST<T>::find(const T &data) {
    /* TODO */
    return find_helper(root, data);
}

template <class T>
void BST<T>::printInorder() {

    if (root == NULL) {
        std::cout << "{}" << std::endl;
    } else {
        std::cout << "{" << std::endl;
        printInorder(root);
        std::cout << std::endl << "}" << std::endl;
    }
}

template <class T>
void BST<T>::printInorder(BSTNode<T> *node) {

    if (node == NULL)
        return;

    printInorder(node->left);
    if (node->left) {
        std::cout << "," << std::endl;
    }
    std::cout << "\t" << node->data;
    if (node->right) {
        std::cout << "," << std::endl;
    }
    printInorder(node->right);
}

template <class T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) {
    /* TODO */
    if(this != &rhs) {
        deleteBST(root);
        copy_helper(root, rhs.root);
    }
    return *this;
}
template <class T>
void BST<T>::deleteBST(BSTNode<T> *&r){
    if (r == NULL)
      return;
    deleteBST(r->left);
    deleteBST(r->right);
    delete r;
    r = NULL;
}
template <class T>
void BST<T>::copy_helper(BSTNode<T> *&rhs, BSTNode<T> *lhs) {
    if(lhs != NULL) {
        rhs = new BSTNode<T>(lhs->data,NULL,NULL);
        copy_helper(rhs->left, lhs->left);
        copy_helper(rhs->right, lhs->right);
    }
    else
        rhs = NULL;

}
template <class T>
void BST<T>::insert_helper(BSTNode<T> *&r, T val) {
   if (r == NULL)
       r = new BSTNode<T>(val,NULL,NULL);
   else if (r->data > val)
       insert_helper(r->left, val);
   else if (r->data < val)
       insert_helper(r->right, val);
}
template <class T>
BSTNode<T> *BST<T>::find_helper(BSTNode<T> *&r, T val){
  if (r == NULL)
     return NULL;
  else{
     if (r->data == val) return r;
     else if (r->data > val) return find_helper(r->left,val);
     else return find_helper(r->right,val);
   }
}
template <class T>
T BST<T>::getMin(BSTNode<T> *r){
    if (r->left == NULL)
        return r->data;
    else
        return getMin(r->left);
  }
template <class T>
void BST<T>::remove_helper(BSTNode<T> *&r, T val){
  if (r == NULL)
      return;
  else if (r->data > val)
      remove_helper(r->left, val);
  else if (r->data < val)
      remove_helper(r->right , val);
  else
      if (r->left != NULL && r->right != NULL) {
         r->data = getMin(r->right);
         remove_helper(r->right, r->data);
      }
      else {
         BSTNode<T> * oldNode =r;  // only  R or L child
         if(r->left != NULL) r = r->left;
         else r = r->right;
         delete oldNode;
      }
}
