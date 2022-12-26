class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count ={}
        freq = [[] for i in range(len(nums) +1)] # [[list] , no]
        for n in nums:
            count[n] = 1 + count.get(n,0) # storing the frequency
        for n,c in count.items(): # n is number, c is count
            freq[c].append(n) # 
        res= []
        for i in range(len(freq) -1 , 0, -1): # looping in reverse order
            for n in freq[i]:
                res.append(n)
                if(len(res)==k):
                    return res #(O(n)) 

