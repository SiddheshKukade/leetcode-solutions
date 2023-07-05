class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        if(len(nums) == nums.count(1)):
            return len(nums)-1 # for all 1s
        count =0
        count1 =0
        maxcount=0
        for k in range(len(nums)):
            if nums[k] != 0: ## if 1s then increse countere
                count = count +1
            else:
                for i in range(k+1, len(nums)): # if 0 found then go to futuher and check other 1s 
                    if nums[i] != 0:
                        count1 = count1+ 1
                    else:
                        break
                if maxcount< count+count1:
                    maxcount = count+count1
                count= 0
                count1=0
        return maxcount
