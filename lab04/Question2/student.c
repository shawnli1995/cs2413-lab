#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



bool isSymmetric(struct TreeNode* root) {
    static struct TreeNode* left;
    static struct TreeNode* right;
    if (root != NULL) {
        left = root->left;
        right = root->right;
        root = NULL;   
    }
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;
    if (left->val != right->val)
        return false;
    struct TreeNode* l1 = left->left;
    struct TreeNode* l2 = left->right;
    struct TreeNode* r1 = right->left;
    struct TreeNode* r2 = right->right;
    left = l1;
    right = r2;
    if (!isSymmetric(NULL))
        return false;
    left = l2;
    right = r1;
    return isSymmetric(NULL);
}