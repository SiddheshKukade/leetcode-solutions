class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        # using prefix sum for optimized answer:
        # Prefix sum just means sum untill a particular index
        ans = 0
        n = len(arr)
        presum = [0]*(n+1) 

        for i in range(n):
            presum[i+1] += presum [i] +arr[i]
        
        for i in range(n):
            for j in range(i+1, n+1):
                if(j-i)%2:
                    ans += presum[j] - presum[i]
        
        return ans
