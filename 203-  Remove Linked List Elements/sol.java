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
    public ListNode removeElements(ListNode head, int val) {
        while(head != null && head.val == val){
            head = head.next; // if a single node is there and it matched then just point to some next random address 
        }
        ListNode curr = head; 
        while(curr != null && curr.next != null){ //if curr is not null and it's next also exists.
            if(curr.next.val == val){
                curr.next = curr.next.next; // skips the node from this list;
            }else{ //no val mach 
                curr= curr.next; // keep iterating over the list.
            }
        }
        return  head;
    }
}
