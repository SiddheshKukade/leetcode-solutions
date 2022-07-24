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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // merge the lists and return the heads
        ListNode* p1=list1; //list 1
        ListNode*  p2=  list2; // list 2 
        ListNode* dummyNode = new ListNode(-1); // dummmy node with dummy value
        ListNode* p3=dummyNode; // pointer for answer list
        
        while(p1!=NULL && p2!=NULL){ // untill one of the  list is NOT empty
            if(p1->val< p2->val){ // check the smaler on e
                p3->next =p1;// if p1 is smaller then attach it and 
                p1=p1->next;//increment its proper pointer
            }
            else{
                p3->next = p2; // else put other in list
                p2=p2->next; // increment p2
            }
            p3=p3->next; // finally increment dummyList to get new element
        }
        //if p1 is still not finished 
        while(p1!=NULL ){
            p3->next = p1;// keep inserting all element of the list 
            p1=p1->next; 
            p3=p3->next;
        }
        //if p2 is still not finished 
         while(p2!=NULL ){
            p3->next = p2;// keep inserting all element of the list 
            p2=p2->next; 
            p3=p3->next;
        }
        return dummyNode->next;
        
//         if(list1->val < list2->val || list1->val == list2->val){
//             temp= list1->next;
//             list1->next= list2;
            
//             temp2 = list2->next;
//             list2->next=temp;
            
//             temp->next = temp2;
//             cout<<temp->next->next->val;
//         }
            
//         return list1;
    }
};
