//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
void place(stack<int> &s , int t){
    if(s.size() == 0 || s.top() <t ) s.push(t);
    
    else{
        int a = s.top();
        s.pop();
        place(s,t);
        s.push(a);
    }
}
void reverse(stack<int> &s){
    if(s.size() > 0 ){
        int t= s.top();
        s.pop();
        reverse(s);
        place(s,t);
        
    }
}





/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   reverse(s);
}