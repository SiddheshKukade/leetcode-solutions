class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        # //can't use dp here
        # //using backtracking
        # //using set to eliminate duplicates
        ans= set()

        def backTrack(start,cur):
            if len(cur) >1:
                ans.add(tuple(cur))
            last = cur[-1] if cur else -200 # if cur exists then add last ele as ans;
        #giving out of range number
        #Backtracking starts.
            for i in range(start,n):
                if nums[i] >= last:#if greater number is found next
                    cur.append(nums[i]) # append that element as ans in cur
                    backTrack(i+1, cur) # check from next index for furthur combinations
                    cur.pop() # remove top element
        n = len(nums)
        backTrack(0,[])

        return ans
