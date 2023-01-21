class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        # Worst case time complexity :O(3^4)
        res=[]
        if len(s) >12: # if possible length to create IP
            return res

        def backtrack(i, dots,curIP):
            if dots ==4 and i ==len(s):
                res.append(curIP[:-1]) # push ans removing the last dot.
            if dots >4:
                return 
            
            for j in range(i,min(i+3, len(s))):
                if int(s[i:j+1]) < 256 and (i==j or s[i] !="0"): # preventing leading zeros with (i==j or s[i] !="0")
                    backtrack(j+1,dots+1, curIP+s[i:j+1]+ ".")
        backtrack(0,0,"")
        return res
