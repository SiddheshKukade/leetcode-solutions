/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        //create a dummy node and just change the directions
        ListNode newHead = null;
        while(head != null){
            ListNode next= head.next; // next node here
            head.next = newHead; // reversing the connection here
            newHead = head; // moving to head as newHead
            head = next; // head goes to next location
            //HEAD IS always ahead of the newHead
        }
        return newHead;
    }
}
