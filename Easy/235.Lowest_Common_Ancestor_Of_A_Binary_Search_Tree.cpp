/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q)
            return NULL;
        TreeNode* node = root;
        TreeNode* result = NULL;
        TreeNode* left = p->val < q->val ? p : q;
        TreeNode* right = p->val > q->val ? p : q;
        while(node)
        {
            if(node->val >= left->val && node->val <= right->val)
            {
                result = node;
                break;
            }
            else if(node->val < left->val)
            {
                node = node->right;   
            }
            else
                node = node->left;
        }
        return result;
    }
};