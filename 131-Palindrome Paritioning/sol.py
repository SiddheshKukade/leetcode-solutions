class Solution:
    def partition(self, s: str) -> List[List[str]]:
        # using depth first tree.
        # Fisrt is all character being separated.
        # The try for two ...then three.
        # TC 2^n
        res =[]
        part = []
        

        def dfs(i):
            if i>=len(s):
                res.append(part.copy())
                return 
            for j in range(i,len(s)):
                if self.isPali(s, i,j):
                    part.append(s[i:j+1]) # update the answer
                    dfs(j+1)
                    part.pop() # Remove the prev results 
        dfs(0)
        return res

    def isPali(self, s,l,r):
        while l<r:
            if s[l] != s[r]:
                return False
            l,r = l+1, r-1
        return True
        
