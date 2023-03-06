class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        # save the strings in a hashmap and then check the couner
        d1 = {}
        d2 = {}

        for i in range(len(s1)):
            if s1[i] == s2[i]:
                pass
            else:
                if s1[i] in d1:
                    return False
                d1[s1[i]] = s2[i]
                d2[s2[i]] = s1[i]

        if d1 == d2 and len(d1) <=2:
            return True
        else:
            return False
