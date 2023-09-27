//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
           //1 node is not req to segregate 
        Node *p=head,*prev=NULL,*oddHead=NULL,*oddptr=oddHead;
        for(;p!=NULL;p=p->next)
        { 
            //Keep even valued node as it is in head 
            //if odd valued node,delete it temporarily and add to a new ll(oddHead)
            if(p->data%2!=0)
            {
                head==p?head=p->next:prev->next=p->next;
                oddHead==NULL?oddHead=p:oddptr->next=p;
                oddptr=p;
            }
            //VVV.IMP-
            //Not req to move prev, when p is at even position node bz after temporarily 
            //delete of even position node p go to odd position node but prev remains just 
            //back of p already
            else
               prev=p;
        }
        
        //append oddHead(containing odd valued nodes) to the end of head
        head==NULL?head=oddHead:prev->next=oddHead;
        
        
         //at the end ,store NULL at the last node
        if(oddptr) oddptr->next=NULL;
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends