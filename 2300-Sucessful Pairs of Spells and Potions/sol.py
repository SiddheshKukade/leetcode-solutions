class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        res = []
        for s in spells:
            l,r =0, len(potions)-1
            idx=len(potions) # find weakest potion that works
            while l<=r:
                # using Binary search
                m = (l+r)//2
                if s * potions[m] >= success:
                    r= m-1
                    idx=m
                else:
                    l = m+1
            res.append(len(potions)-idx) # subtract the idx from size

        return res
