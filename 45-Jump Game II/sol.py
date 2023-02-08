class Solution:
    def jump(self, nums: List[int]) -> int:
        # what is min jumps it takes to reach the last index.
        # This is a greddy type of problem.
        # BFS in one dimensional array.
        res = 0
        l = r = 0
        while r<len(nums) -1: #untill right reaches to the last value.
            farthest = 0 # it is the max jump which is possible.
            for i in range(l,r+1): # from left to untill right pointer
                farthest = max(farthest, i+nums[i]) #storing the max jump
            l = r + 1 # just one position after i
            r = farthest # the farthest possiblee position.
            res +=1 # count the jump
        return res
