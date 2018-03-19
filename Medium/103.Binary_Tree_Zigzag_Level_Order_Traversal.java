Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new LinkedList();
        if(root == null)
            return result;
        Stack<TreeNode> layerElementsA = new Stack();
        Stack<TreeNode> layerElementsB = new Stack();
        layerElementsA.push(root);
        List<Integer> layer = new ArrayList();
        Boolean rightToLeft = true;
        while(!layerElementsA.empty())
        {
            TreeNode node = layerElementsA.pop();
            layer.add(node.val);
            if(rightToLeft == true) {
                if(node.left != null)
                    layerElementsB.push(node.left); 
                if(node.right != null)
                    layerElementsB.push(node.right);  
            } else {                  
                if(node.right != null)
                    layerElementsB.push(node.right);
                if(node.left != null)
                    layerElementsB.push(node.left);
            }
            if(layerElementsA.empty()) {
                if(rightToLeft == false) {                    
                    rightToLeft = true;
                } else {
                    rightToLeft = false;                    
                }
                Stack<TreeNode> tmp = layerElementsA;
                layerElementsA = layerElementsB;
                layerElementsB = tmp;
                result.add(layer);
                layer = new ArrayList();
            }            
        }
        return result; 
        
    }
}