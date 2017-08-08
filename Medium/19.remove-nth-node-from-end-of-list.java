/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list
 *
 * algorithms
 * Medium (33.39%)
 * Total Accepted:    185.9K
 * Total Submissions: 556.7K
 * Testcase Example:  '[1]\n1'
 *
 * Given a linked list, remove the nth node from the end of list and return its
 * head.
 * 
 * 
 * For example,
 * 
 * 
 * ⁠  Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * ⁠  After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 * 
 */

/**
 *  * Definition for singly-linked list.
 *   * public class ListNode {
 *    *     int val;
 *     *     ListNode next;
 *      *     ListNode(int x) { val = x; }
 *       * }
 *        */
public class Solution {
        public ListNode removeNthFromEnd(ListNode head, int n) {
            if(n <= 0)
                return head;
            if(n == 1 && head.next == null)
                return null;
            ListNode fakeHead = new ListNode(0);
            fakeHead.next = head;
            ListNode first = fakeHead;
            int count = n;
            while(count > 0)
            {
                count--;
                first = first.next;
                if(first == null)
                    return head;
            }
            
            ListNode second = fakeHead;
            while(first.next != null)
            {
                first = first.next;
                second = second.next;
            }
            second.next = second.next.next;
            return fakeHead.next;
                                                                                                                  
        }
}
