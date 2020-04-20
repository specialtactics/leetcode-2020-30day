/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* newNode(int value);
void insertTreeNode(struct TreeNode *root, struct TreeNode *node);

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    if (preorderSize == 0) {
        return NULL;
    }
    
    struct TreeNode* root = newNode(preorder[0]);
    
    for (int i = 1; i < preorderSize; ++i) {
        insertTreeNode(root, newNode(preorder[i]));
    }
    
    return root;
}

/**
 * Insert into tree
 */
void insertTreeNode(struct TreeNode *root, struct TreeNode *node) {
    if (node->val < root->val) {
        if (root->left != NULL) {
            insertTreeNode(root->left, node);
        } else {
            root->left = node;
        }
    } else {
        if (root->right != NULL) {
            insertTreeNode(root->right, node);
        } else {
            root->right = node;
        }
    }
}


/**
 * Make new node
  */
struct TreeNode* newNode(int value) {
    struct TreeNode* new = malloc (sizeof(struct TreeNode));
    
    new->val = value;
    new->left = NULL;
    new->right = NULL;
    
    return new;
}
