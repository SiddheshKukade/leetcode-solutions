//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 
int findPages(int arr[], int N, int m) {
    if (m > N) return -1;
    
    int low = *std::max_element(arr, arr + N);
    int high = 0;
    for (int i = 0; i < N; i++) {
        high += arr[i];
    }
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, N, mid);
        
        if (students > m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return low;
}
int countStudents(int arr[], int N, int pages) {
    int students = 1;
    long long pagesStudent = 0;
    
    for (int i = 0; i < N; i++) {
        if (pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        } else {
            students++;
            pagesStudent = arr[i];
        }
    }
    
    return students;
}

 

    int splitArray(int arr[] ,int N, int K) {
         return findPages(arr, N, K);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends