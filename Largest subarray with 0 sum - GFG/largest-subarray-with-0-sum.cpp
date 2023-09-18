//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        ///store in hashset for prefix sum and then check if sum is repeating means we have some zerosum subarrays in between.
        // TC N log n
        // / n for traveffsal and log n for hashmap/
        // SC :  O N  hasmap
        unordered_map<int, int> mp ;
        int mx=0;
        int sum =0;
        
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum ==0){
                mx = i+1;
            }else{
                if(mp.find(sum) != mp.end()){
                    mx = max(mx,i-mp[sum]);
                }else{
                    mp[sum] = i;
                }
            }
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends