/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//  USING A HARE AND TORTOISE 2 POINTER SOLUTION.
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // IF slow and fast pointers are meeting each other then there is a cucle present.
        ListNode* slow = head;
        ListNode* fast = head;
        bool cyclefound = false;
        while(fast  && fast->next ){
            slow = slow->next; // 1 step;
            fast = fast->next->next; // 2 step at a time

            if(slow == fast){
                cyclefound = true;
                break;
            }
        }
        // if cycle found -> move both pointer by one step anad finlly you will reach to the 
        // start of the cycle (shift any one pointer to head)
        if(!cyclefound) return NULL;
        fast = head;
        while(slow != fast){
            slow = slow->next; 
            fast = fast->next; 
        }
        return slow;
    }
};
