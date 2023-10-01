//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{


public:
     void solve(vector<string> vect,int index,string &lstr,vector<string> &ans)
    {
        if(index == vect.size()){
         ans.push_back(lstr);
         return;
        }
        
        for(int i=0;i<vect[index].length();i++)
        {
            string x = vect[index];
            lstr.push_back(x[i]);
            solve(vect,index+1,lstr,ans);
            lstr.pop_back();
            
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> vect;
        vector<string> str;
        vector<string> ans;
        string lstr;
        str = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i=0;i<N;i++)
        {
            vect.push_back(str[a[i]-2]);
        }
        
        solve(vect,0,lstr,ans);
        
        return ans;                          
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends