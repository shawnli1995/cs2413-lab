/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
static int checkAVL(struct TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return 0; 

    if ((long long)node->val <= minVal || (long long)node->val >= maxVal)
        return -1; 

    int leftH = checkAVL(node->left, minVal, node->val);
    if (leftH == -1) return -1;

    int rightH = checkAVL(node->right, node->val, maxVal);
    if (rightH == -1) return -1;

    if (leftH - rightH > 1 || rightH - leftH > 1) return -1; 

    return 1 + (leftH > rightH ? leftH : rightH);
}

bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    return checkAVL(root, LLONG_MIN, LLONG_MAX) != -1;
}
