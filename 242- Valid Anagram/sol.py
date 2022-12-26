class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
# Getting the solution in O(1) complexity o(1)
# sort the strings first and then check only once. (time complexity of sorting is not considered in the interview)
            return sorted(s) == sorted(t)

# using hashmap to keep count of characters and their occurence counts. TC = > o(S+T)
        #   OBE LINER  SOL SPECIALLY FOR PYTHON
        #  uses counter which is a built in ds in py that counts the occurnces automatically
            return Counter(s) == Counter(t)
            if len(s) != len(t):
                return False
            countS, countT=  {}, {}

            for i in range(len(s)):
                countS[s[i]] = 1 + countS.get(s[i], 0) # 0 is default value 
                countT[t[i]] = 1 + countT.get(t[i], 0) # 0 is default value 
            
            for c in countS:
                if countS[c] != countT.get(c,0):
                    return False
            
            return True
