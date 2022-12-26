
class Solution:
    def alphaNum(self,c):
        return (ord('A') <= ord(c) <= ord('Z') or 
        ord('a') <= ord(c) <= ord('z') or
        ord('0') <= ord(c) <= ord('9'))
    def isPalindrome(self, s: str) -> bool:
        # only considering alphanumerics for the palindrom check

        #2 o(n) space o(1)
        # using ASCII to check alphanumerics
    
        l , r  = 0, len(s) -1 
        while(l<r):
            while l<r and not self.alphaNum(s[l]):
                l+=1
            while r>l and not self.alphaNum(s[r]):
                r-=1
            if s[l].lower() != s[r].lower():
                return False
            l,r = l+1, r-1
        return True
        #1 o(n) space extra string used
        #Using built in method for alphanumeric check
        # newStr =""
        # for c in s:
        #     if c.isalnum():
        #         newStr +=c.lower()
        # return newStr == newStr[::-1]


