class SummaryRanges:

    def __init__(self):
        self.ranges = []
        self.numSet = set()        

    def addNum(self, value: int) -> None:
        self.numSet.add(value) # all the  values that we're adding is getting saved in the  numSet

    def getIntervals(self) -> List[List[int]]:
        nums = sorted(list(self.numSet)) 
        res=[]
        i=0
        while i<len(nums): # linear time algo
            start = nums[i] # first element
            while i+1 < len(nums) and nums[i] + 1 == nums[i+1]: # if next numbers are coming record the range
                i+=1 # only move forward if next nos are present
            res.append([start,nums[i]]) # and add to the answer
            i+=1 # move foreard anyways to continue the loop
        return res # return the answer


# Your SummaryRanges object will be instantiated and called as such:
# obj = SummaryRanges()
# obj.addNum(value)
# param_2 = obj.getIntervals()
