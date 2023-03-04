class Solution:
    def hammingWeight(self, n: int) -> int:
        # # Approach 1
        #  TC - O(32) constant time aka O(1) 
        res = 0
        while n:
            res +=n %2 # can be a 1 or 0 showing if the last bit is set or not
            n = n  >> 1 # Shifting the bits to the right 
        return res

        # Approach 2
        res= 0
        while n:
            n= n&(n-1)
            res +=1
        return res
