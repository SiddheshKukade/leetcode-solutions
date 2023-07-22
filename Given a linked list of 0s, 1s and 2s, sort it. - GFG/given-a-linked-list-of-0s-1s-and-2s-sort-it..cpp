//{ Driver Code Starts
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

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
    void insert_at_head(Node *&head,int data){
        if(head==NULL){
            head=new Node(data);
            return;
        }
        Node *temp=new Node(data);
        temp->next=head;
        head=temp;
    }
    Node* segregate(Node *head) {
        
        // Add code here
        map<int,int>mp;
        while(head!=NULL){
            mp[head->data]++;
            head=head->next;
        }
        Node *temp=NULL;
        while(mp[2]>0){
            insert_at_head(temp,2);
            mp[2]--;
        }
        while(mp[1]>0){
            insert_at_head(temp,1);
            mp[1]--;
        }
        while(mp[0]>0){
            insert_at_head(temp,0);
            mp[0]--;
        }
        return temp;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends