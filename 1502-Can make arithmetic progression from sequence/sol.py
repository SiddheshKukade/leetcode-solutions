class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        # SORTING TO GET CORRECT RESULTS
        arr.sort()
        # STORING THE FIRST DIFFERENCE TO CHECK FURTHER
        d = arr[1] - arr[0]
        # LOOP OVER THE ENTIRE ARR from 2 becase already checked for 0 and 1
        for i in range(2,len(arr)):
            # IF  DIFF IS NOT SAME
            if(arr[i]-arr[i-1] != d):
                return False
        return True
