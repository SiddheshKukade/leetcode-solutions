//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        //  int cnt=0;
        // vector<double>v;
        // vector<double>k;
        // for(int i=0;i<n;i++){
        //     auto frac=(double)numerator[i]/denominator[i];
        //     v.push_back(frac);
        // }
        //     for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         auto y=v[i]+v[j];
        //         k.push_back(y);
        //     }
        // }
        //     for(int i=0;i<k.size();i++){
        //     if(k[i]==1.0000){
        //         cnt++;
        //     }
        // }
        // return cnt;
        
            map<double , int> mp;
        int ans = 0;//COUNT OF THE ANSWER
        for(int i = 0;i<n;i++)
        {
            double a = (numerator[i]*1.0/denominator[i]);//X
            double b = (denominator[i] - numerator[i])*1.0/denominator[i]; //Y
            ans+=mp[b];
            mp[a]++;
        }
        return ans;
        
        
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends