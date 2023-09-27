//{ Driver Code Starts
//Initial Template for C++
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/

// } Driver Code Ends
/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
class Solution{
public:
 Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
    
        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
    
        return prev;
    }
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
            if (head == nullptr)
            return -1;
    
        Node* reversedHead = reverseList(head);
    
        int count = 1;
        Node* current = reversedHead;
    
        while (current != nullptr && count < n) {
            current = current->next;
            count++;
        }
    
        if (current == nullptr)
            return -1;
    
        return current->data;
    }
    
};



//{ Driver Code Starts.

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends