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

/*this solution cost the least time*/
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q)
            return NULL;
        if(root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right)
            return root;
        else
            return left ? left : right;
    }
};

 #include <deque>
class Solution3 {
public:
    TreeNode* getCommNode(deque<TreeNode*>& pathP, deque<TreeNode*>& pathQ)
    {
        if(pathP.empty() || pathQ.empty())
            return NULL;
        TreeNode* result = NULL;
        while(!pathP.empty() && !pathQ.empty() && pathP.front() == pathQ.front())
        {
            result = pathP.front();
            pathP.pop_front();
            pathQ.pop_front();
        }
        return result;
    }
    bool getPath(TreeNode* root, TreeNode* p, TreeNode* q, deque<TreeNode*>& pathP, deque<TreeNode*>& pathQ)
    {
        if(!root || !p || !q || !pathP.empty() || !pathQ.empty())
            return false;
        TreeNode* node = root;
        TreeNode* lastVisited = NULL;
        deque<TreeNode*> nodeDeque;
        while(!nodeDeque.empty() || node)
        {
            if(node)
            {
                nodeDeque.push_back(node);
                node = node->left;
            }
            else
            {
                node = nodeDeque.back();
                if(!node->right || node->right == lastVisited)
                {
                    lastVisited = node;
                    if(node == p)
                    {
                        pathP = nodeDeque;
                    }
                    if(node == q)
                    {
                        pathQ = nodeDeque;
                    }
                    node = NULL;
                    nodeDeque.pop_back();
                    if(!pathP.empty() && !pathQ.empty())
                        return true;
                }
                else
                {
                    node = node->right;
                }
            }
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(!root || !p || !q)
            return NULL;
        deque<TreeNode*> pathP, pathQ;
        getPath(root, p, q, pathP, pathQ);
        return getCommNode(pathP, pathQ);
    }
};