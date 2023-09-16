//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
              const long long MOD = 1000000007;
        // your code here
        if (n == 0 || n == 1) return 1;
        if (n == 2) return 2;
    
        // Initialize the only three variables to store results of the last three steps
        long long step_minus_3 = 2, step_minus_2 = 1, step_minus_1 = 1;
    
        // Current step value
        long long current = 0;
    
        for (int i = 3; i <= n; i++) {
            // Calculate current ways
            current = (step_minus_1 + step_minus_2 + step_minus_3) % MOD;
    
            // Update for next iteration
            step_minus_1 = step_minus_2;
            step_minus_2 = step_minus_3;
            step_minus_3 = current;
        }
        
        return current;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends