#pragma once
#include <iostream>
using namespace std;

template <class T>
struct TreeNode {
    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
    T data;
    TreeNode* left;
    TreeNode* right;
};

//Binary Search Tree
template <class T>
class BST {
public:
    BST() : root(nullptr), num(0) {}
    bool isEmpty() const { return root == nullptr; }
    int size() const { return num; }

    void insertArray(T*, int size);
    void insert(const T& value) { root = insertBST(root, value); num++; }
    bool search(const T& value) const { return searchInBST(root, value) != nullptr; }

    void inorder() const { inorderTraversal(root); cout << endl; }
    void preorder() const { preorderTraversal(root); cout << endl; }
    void postorder() const { postorderTraversal(root); cout << endl; }

    void destroyTree() { destroy(root); root = nullptr; num = 0; }
    ~BST() { destroyTree(); }

private:
    TreeNode<T>* root;
    int num;

    TreeNode<T>* insertBST(TreeNode<T>* node, const T& value);
    TreeNode<T>* searchInBST(TreeNode<T>* node, const T& value) const;
    void inorderTraversal(TreeNode<T>* node) const;
    void preorderTraversal(TreeNode<T>* node) const;
    void postorderTraversal(TreeNode<T>* node) const;
    void destroy(TreeNode<T>* node);
};

#include "BST.tpp" // keep this for template definitions
