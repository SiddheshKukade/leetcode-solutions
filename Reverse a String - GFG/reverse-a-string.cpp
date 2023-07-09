//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

string reverseWord(string str){
    
    int s=0,e=str.size()-1;
    while(s<=e){
        char t= str[s];
        str[s] = str[e];
        str[e] = t;
        
        s++;
        e--;
    }
    return str;
  //Your code here
}



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends