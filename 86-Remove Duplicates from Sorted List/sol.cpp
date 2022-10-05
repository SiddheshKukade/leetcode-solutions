class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* node = head;
        while(node != nullptr && node->next != nullptr){
            if(node->val == node->next->val ){
                ListNode* temp = node->next;
                node->next = node->next->next;
                delete temp;
            }else{
                node = node->next;
            }
        }
        return head;
    }
};
