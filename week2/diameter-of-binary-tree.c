// Simple implementation of max from stack
 #define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int diameterOfBinaryTree(struct TreeNode* root) {
    // Special cases
    if (root == NULL || root->left == NULL && root->right == NULL) {
        return 0;
    }

    int highestSum = 0;
    int longestDistance = longest(root, &highestSum) - 1; // Subtract 1 for root
    
    return max(longestDistance, highestSum);
}

/**
 * Return longest distance for one node
 */ 
int longest(struct TreeNode* node, int* highestSum) {
    int right = 0, left = 0;
    
    if (node->left != NULL) {
        left = longest(node->left, highestSum);
    }
    if (node->right != NULL) {
        right = longest(node->right, highestSum);
    }
    
    // Maintain highest sum
    if (right + left > (*highestSum)) {
        *highestSum = right + left;
    }
    
    return (max(left, right) + 1);
} 
