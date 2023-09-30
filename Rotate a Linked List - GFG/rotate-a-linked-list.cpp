//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // // Your code here
        //   if(head == NULL  || head->next == NULL ||k ==0)  return head;
        // int len = 1;
        // Node* curr= head;
        // while(curr->next!= NULL && ++len) curr= curr->next;

        // curr->next= head;

        // k = k%len;
        // k = len - k; 
        // while(k--){
        //     curr=curr->next;
        // }
        // head = curr->next;
        // curr->next = NULL;
        
        
        // return head;
        
                // Your code here
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
        for(int i=1;i<=k;i++)
        {
            head = head->next;
            temp = temp->next;
        }
        temp->next = NULL;
        return head;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends