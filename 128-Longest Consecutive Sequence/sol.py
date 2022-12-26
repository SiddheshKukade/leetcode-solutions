class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # TC MC o(N)
        numSet = set(nums) # remvoe previous duplicates
        longest = 0

        for n in nums:
            # check if it's the start of a sequence
            if(n-1) not in numSet: # if does not have left neighbour the consider as the starting point
                length =0
                while(n+length) in numSet: # if consecutive is present 
                    length+=1 # keep incrementing the length
                longest=max(length,longest) # keep updating the current length with the longest avaialable
        return longest
