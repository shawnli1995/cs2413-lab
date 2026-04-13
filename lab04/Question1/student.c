#include <stddef.h>

/*
Question 1: Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

The maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.

Examples:

Example 1:
Input:
        1
       / \
      2   3
Output: 2

Example 2:
Input:
        1
       /
      2
     /
    3
Output: 3

Example 3:
Input: empty tree
Output: 0

Function to complete:
    int maxDepth(struct TreeNode* root);

Note:
- If the tree is empty, return 0.
- A tree with only one node has depth 1.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
  // TODO: implement
    if (root == NULL) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
}