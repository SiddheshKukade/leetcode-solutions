//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
  Node* merge(Node* left, Node* right){
      
      if(left == NULL) {
          return right;
      }else if(right == NULL){
          return left;
      }
      Node* ans = new Node(-1);
      Node* temp = ans;
      while(left != NULL && right != NULL){
          if(left->data < right->data){
              temp->next=  left;
              temp= left;
              left= left->next;
          }else{
              temp->next= right;
              temp = right;
              right = right->next;
          }
      }
      
      while(left != NULL){
             temp->next=  left;
              temp= left;
              left= left->next;
      }
      while(right != NULL){
             temp->next=  right;
              temp= right;
              right= right->next;
      }
      
      /////removing the initial dummy node
      ans = ans->next;
      return ans;
  }
   Node* findMid(Node* head){
       Node* slow = head;
       Node* fast= head->next;
       while(fast != NULL && fast->next != NULL){
           slow = slow->next;
           fast= fast->next->next;
       }
       return slow;
   }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here+
        // TC O N*LOGN
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* mid = findMid(head);
        
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        ///sorting recursively.
        left = mergeSort(left);
        right = mergeSort(right);
        
        ///merge both l and r half
        Node* result = merge(left, right);
        return result;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends