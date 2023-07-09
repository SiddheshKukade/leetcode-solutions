//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here
         int low=0,mid=0,high=n-1;
        while(high>=mid){
            switch(a[mid]){
                //If the element is 0
                case 0:
                swap(a[low++],a[mid++]);
                break;
                
                 //If the element is 1
                case 1:
                mid++;
                break;
                
                 //If the element is 2
                 case 2:
                 swap(a[mid],a[high--]);
                 break;
            }
        }
        // return a;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends