/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry= 0;
        
        while(l1 !=NULL || l2 != NULL || carry){ // make sure lists are not null 
            int sum =0 ;
            if(l1 !=NULL){ // if first is not null
                sum += l1->val; // add val to sum
                l1 = l1->next;// move l1 to next
            }
            if(l2!=NULL){ // if second is not null
                sum += l2->val; // add val to the sum 
                l2=l2->next; // move l2 to next
            }
            sum += carry; // add sum with carry (if any)
            carry=sum /10; //divide by 10 to get the carry
            ListNode *node= new ListNode(sum % 10); //create new node to store the value with keeping the carry
            temp->next = node;// 
            temp = temp->next;
        }
        return dummy->next; // return the final answer 
    }
};
