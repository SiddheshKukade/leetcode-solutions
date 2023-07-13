//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        // sort(arr, arr+n);
        // for(int i=1; i<n; i++){
        //     cout<<arr[i-1];
        //     if(arr[i-1] ==arr[i] ){
        //         return false;
        //     }
        // }
        // return true;
        map<int, int> m;
        for(int i=0; i<n;i++){
            m[arr[i]]++;
        }
        vector<int>v;
        for(auto it=m.begin();it!=m.end();it++)
            v.push_back((*it).second);
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1])return false;
        }
        return true;
        // for(auto x: mp){
        //             cout<<x.second<<endl;
        //     if(x.second>=2){
        //         cout<<x.second<<endl;
        //         return false;
        //     }
        // }
        // return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends