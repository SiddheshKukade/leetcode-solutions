//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
public:
    pair<struct node *, struct node *> reverseGroup(struct node *prevHead, struct node *head, struct node *tail)
    {
        struct node *curr = head, *next, *prev = NULL, *tailNext = tail->next;
        while (curr != tail)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (curr == tail)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = tailNext;
        if (prevHead)
            prevHead->next = tail;
        return {tail, head};
    }

    // including head
    struct node *kthPosition(struct node *head, int k)
    {
        int cnt = 1;
        while (head->next != NULL && cnt < k)
        {
            head = head->next;
            cnt++;
        }
        return head;
    }

    struct node *reverse(struct node *head, int k)
    {
        struct node *curr = head, *prev = NULL, *next, *res = NULL;
        pair<struct node *, struct node *> temp;
        do
        {
            next = kthPosition(curr, k);
            temp = reverseGroup(prev, curr, next);
            prev = temp.second;
            curr = prev->next;
            if (res == NULL)
                res = temp.first;
        } while (prev->next);
        return res;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends