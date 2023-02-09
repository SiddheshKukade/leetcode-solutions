class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        #map first chat -> list of word suffixes
        wordMap = collections.defaultdict(set)
        for w in  ideas:
            wordMap[w[0]].add(w[1:])
        res =0
        for char1 in wordMap:
            for char2 in wordMap:
                if char1 == char2 :
                    continue
                intersect =0

                for w in wordMap[char1]:
                    if w in wordMap[char2]: # if the suffix also exists in the other word the add as duplicate
                        intersect +=1
                
                distinct = len(wordMap[char1]) - intersect
                distinct2 = len(wordMap[char2]) - intersect
                res += distinct * distinct2 # possible words will be combinations of distinct words that is why we are multiplying here.
                    
        return res

