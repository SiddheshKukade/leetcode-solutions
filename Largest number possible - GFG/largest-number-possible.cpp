//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        // code here
              string  str;
     
     if(s==0 && n>1) return "-1";   
     for(int i=0 ; i<n ; i++)
       {
           if(s>=9)
           {
               str.push_back('9');
               s=s-9;
           }
           else 
           {
               if(s==0 )
               {
               str.push_back('0');
               }
               else
               {
                  str.push_back(s+'0');
                  s=s-s;
               }
           }
       }
   
       if(s!=0 ) return "-1";
       
       return str;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends