/*
 * Assignment 2 / Question 1 / student.c
 * ------------------------------------------------------------
 * Search in a Binary Search Tree (BST)
 *
 * Implement:
 *   struct TreeNode* bstSearch(struct TreeNode* root, int target);
 *
 * Rules:
 * - Return a pointer to the node with value == target, else NULL.
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run1
 */

#include <stddef.h>  

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
  if (root == NULL) return NULL;         
    if (root->val == target) return root;   
    if (target < root->val)
        return bstSearch(root->left, target);   
    else
        return bstSearch(root->right, target);  
    
    (void)root;
    (void)target;
    return NULL;
}