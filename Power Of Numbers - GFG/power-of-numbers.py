class Solution:
    def power(self, N, R):
        MOD = int(1e9 + 7)

        # Recursive helper function for modular exponentiation
        def power_helper(base, exponent):
            if exponent == 0:
                return 1
            elif exponent % 2 == 0:
                sub_result = power_helper(base, exponent // 2)
                return (sub_result * sub_result) % MOD
            else:
                sub_result = power_helper(base, exponent // 2)
                return (base * sub_result * sub_result) % MOD

        # Calculate the result using modular exponentiation
        result = power_helper(N, R)
        return result
        
        # return pow(N%MOD,R%MOD) % MOD
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
    
    T=int(input())
    
    while(T>0):
        
        N=input()
        R=N[::-1]
        
        ob=Solution();
        ans=ob.power(int(N),int(R))
        print(ans)
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends