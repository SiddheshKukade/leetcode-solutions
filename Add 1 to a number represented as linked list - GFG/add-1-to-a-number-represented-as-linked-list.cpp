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
        cout << node->data%10; 
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

class Solution
{
    public:
     Node* reverse(Node* head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        Node* curr=head;
        Node* prev=NULL;
        Node* forw=NULL;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
            Node* rev=reverse(head); //// 1209 => 9021
        Node* temp=rev; // 9 0 2 1 
        int carry=1;
        while(temp!=NULL){
            int c=temp->data;
            temp->data=(c+carry)%10;
            carry= (c+carry)/10;
            temp=temp->next;// 0 2 1 
        }
        Node* fi=reverse(rev);
        if(carry==1){ //// if 999999 then 
            Node* first=new Node(1);// add one
            first->next=fi;
            return first;
        }
        return fi;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends