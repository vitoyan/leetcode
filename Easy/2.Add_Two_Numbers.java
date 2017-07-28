/**
* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
* 
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	if(l1 == null)
                return l2;
        if(l2 == null)
                return l1;
        ListNode result, p, q, tmp;
        result = null;
        tmp = null;
        p = l1;
        q = l2;
        int tmpS = 0;
        while(p != null || q != null) {
                int newNodeVal = 0;
                if(p != null && q != null) {
                    newNodeVal = (q.val) +(p.val) + tmpS;
                    p = p.next;
                    q = q.next;
                } else if(p == null) {
                        newNodeVal = q.val + tmpS;
                        q = q.next;
                } else if(q == null){
                        newNodeVal = p.val + tmpS;
                        p = p.next;
                }          
                               
                tmpS = newNodeVal / 10;
                newNodeVal = newNodeVal % 10;
               
                if(tmp != null) {
                        tmp.next = new ListNode(newNodeVal);
                        tmp = tmp.next;
                } else {
                        tmp = new ListNode(newNodeVal);
                        result = tmp;
                }
        }
        if(tmpS != 0)
            tmp.next = new ListNode(tmpS);
        
        return result;
    }
}
