class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res= defaultdict(list) # mapping charCount to list of Anagrams Defining a dictionary with values as a list
        for s in strs:
            count  = [0] * 26 # a..z it will have 26 zeros. 

            for c in s:
                # storing the occurnce of characters
                count[ord(c) - ord("a")] += 1 # mapping a to z to [0 to 26]
                # a=80
                # b=81 -> 1 , 81->80
            res[tuple(count)].append(s) # just adding the ans to list 
        return res.values() # o(m *n ) m isa size n is char each string
