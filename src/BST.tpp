#include "BST.h"

template <class T>
TreeNode<T>* BST<T>::insertBST(TreeNode<T>* node, const T& value) {
    if (node == nullptr) return new TreeNode<T>(value);
    if (value < node->data) node->left = insertBST(node->left, value);
    else node->right = insertBST(node->right, value);
    return node;
}

template <class T>
TreeNode<T>* BST<T>::searchInBST(TreeNode<T>* node, const T& value) const {
    if (node == nullptr) return nullptr;
    if (node->data == value) return node;
    if (value < node->data) return searchInBST(node->left, value);
    else return searchInBST(node->right, value);
}

template <class T>
void BST<T>::inorderTraversal(TreeNode<T>* node) const {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

template <class T>
void BST<T>::preorderTraversal(TreeNode<T>* node) const {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

template <class T>
void BST<T>::postorderTraversal(TreeNode<T>* node) const {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

template <class T>
void BST<T>::destroy(TreeNode<T>* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

template <class T>
void BST<T>::insertArray(T* arr, int size)
{
    if (size == 0)
        return;
    for (int i = 0; i < size; i++)
        insert(arr[i]);

}

