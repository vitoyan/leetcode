/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    bool covers(TreeNode* root, TreeNode* p)
    {
        if(root == NULL) return false;
        if(root == p) return true;
        return covers(root->left, p) || covers(root->right, p);
    }
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        
        bool left = covers(root->left, p);
        bool right = covers(root->right, q);
        
        if(left == right) return root;
        return helper(left?root->left:root->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q)
            return NULL;
        if(!covers(root, p) || !covers(root, q))
            return NULL;
        return helper(root, p, q);
    }
};