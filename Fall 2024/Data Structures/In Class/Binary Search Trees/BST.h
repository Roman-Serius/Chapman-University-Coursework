#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include <iostream>
using namespace std;

template <typename T>
class BST{
    public:
        BST();
        virtual ~BST();
        int getSize();
        int getMin();
        bool contains(T data);
        void insert(T data);
        void remove(T data);
   
    
    private:
        TreeNode<T>* m_root;
        int m_size;
        bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
        void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
        void findTarget(T key, Treenode<T>*& target, TreeNode<T>*& parent);
        int getMinHelper(TreeNode<T>* subTreeRoot);
};

template <typename T>
BST<T>::BST(){
    m_root = NULL;
    m_size = 0;
    
}

template <typename T>
BST<T>::~BST(){
    //free memory
    if(m_root != NULL){
        delete m_root;
  }
}

template <typename T>
int BST<T>::getSize(){
    return m_size;
}

template <typename T>
int BST<T>::getMin(){
    
    return getMinHelper(m_root);
}

template <typename T>
int BST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_left == NULL){
        return subTreeRoot->m_data;
    }
    else{
        return getMinHelper(subTreeRoot->m_left);
    }
}

template <typename T>
bool BST<T>::contains(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    return containsHelper(m_root, newNode);
}

template <typename T>
bool BST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        return false;
    }else if(newNode->m_data == subTreeRoot->m_data){
        return true;
    }else if(newNode->m_data < subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_left, newNode);
    }else if(newNode->m_data > subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_right, newNode);
    }
}

template <typename T>
void BST<T>::insert(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    insertHelper(m_root, newNode);
    m_size++;
}

template <typename T>
void BST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        subTreeRoot = newNode;
    }
    else if(newNode ->m_data < subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_left, newNode);
    }
    else if(newNode ->m_data > subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_right, newNode);
    }
}

template <typename T>
void BST<T>::findTarget(T key, Treenode<T>*& target, TreeNode<T>*& parent){
    while(target != NULL && target->m_data != key){
        parent = target;
        if(key < target->m_data){
            target = target->m_left;
        }
        else if(key > target->m_data){
            target = target->m_right;
        }
    }
}

template <typename T>
void BST<T>::remove(T data){
    //check if empty
    TreeNode<T>* target = NULL;
    Treenode<T>* parent = NULL;
    target = m_root;
    findTarget(data, target, parent);
    if(target == NULL){//value wasn't in tree
        return;
    }
    //check if leaf
    if(target->m_left == NULL && target->m_right == NULL){
        if(target == m_root){ //leaf is root
            m_root = NULL;
        }
        else{//not the root
            if(target == parent->m_left){
                parent->m_left = NULL;
            }else{
                parent->m_right = NULL;
            }
        }
        delete target;
    }
    else if(target->m_left != NULL && target->m_right != NULL){//2 child

    }
    else{ //1 child

    }
}

#endif