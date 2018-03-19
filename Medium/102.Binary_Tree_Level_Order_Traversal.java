Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new LinkedList();
        if(root == null)
            return result;
        Stack<TreeNode> layerElementsA = new Stack();
        Stack<TreeNode> layerElementsB = new Stack();
        layerElementsA.push(root);
        List<Integer> layer = new ArrayList();
        while(!layerElementsA.empty())
        {
            TreeNode node = layerElementsA.pop();
            layer.add(node.val);
            if(node.left != null)
                layerElementsB.push(node.left);
            if(node.right != null)
                layerElementsB.push(node.right);                                   
            if(layerElementsA.empty()) {
                while(!layerElementsB.empty()) {
                    layerElementsA.push(layerElementsB.pop());
                }
                result.add(layer);
                layer = new ArrayList();
            }            
        }
        return result;      
        
    }
}