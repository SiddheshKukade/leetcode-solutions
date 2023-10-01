//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
      void solve(int ind , int target ,  vector<int> &arr , vector<vector<int>> &ans , vector<int> &ds){
        if(ind == arr.size()){
            if(target ==0){
                ans.push_back(ds);
            }
            return ;
        }
        //pick 
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            solve(ind, target- arr[ind] , arr, ans, ds); // remove the current after pick
            ds.pop_back(); // pop back that element after it is returned 
            // returned only when the combination is found
        }
        //not pick 
        //because the index is larger than current target so not pick and move to the next index of the given array
        solve(ind+1, target, arr, ans, ds);
        
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        set<int> st(A.begin(),A.end());
        vector<int> Arr(st.begin(),st.end());
        // Your code here
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, B, Arr, ans, ds);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends