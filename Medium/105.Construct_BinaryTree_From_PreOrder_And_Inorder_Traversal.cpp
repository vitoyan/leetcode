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
    unordered_map<int, int> hashMap;
    TreeNode *build(vector<int>& preorder, int startPre, int endPre, vector<int>& inorder, int startIn, int endIn)
    {
        if(preorder.empty() || inorder.empty())
            return NULL;
        if(startPre > endPre || startIn > endIn)
            return NULL;
        TreeNode* root = new TreeNode(preorder[startPre]);
        int rootNumber = hashMap[preorder[startPre]];
        int sizeOfLeft = rootNumber - startIn;
        int sizeOfRight = endIn - rootNumber;
        if(sizeOfLeft > 0)
            root->left = build(preorder, startPre + 1, startPre + sizeOfLeft, inorder, startIn, startIn + sizeOfLeft - 1);
        
        if(sizeOfRight > 0)
            root->right = build(preorder, startPre + sizeOfLeft + 1, endPre, inorder, startIn + sizeOfLeft + 1, endIn);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return NULL;
        
        for(int i = 0 ; i < (int)inorder.size(); i++)
        {
            hashMap[inorder[i]] = i;
        }
        
        return build(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1);
    }
};