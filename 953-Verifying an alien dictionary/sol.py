class Solution(object):
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        # first differernt character
        # if word A is prefix of word B then word B must be AFTER word A
        #enumerate in pythonb gives the index and the character
        orderInd = {c: i for i,c in enumerate(order)}

        for i in range(len(words)-1):
            w1, w2= words[i], words[i+1] # w2 comes after w1 

            for j in range(len(w1)):
                if j == len(w2): # w2 is finsiehd the w2
                    return False
                if w1[j] != w2[j]:
                    # now check for the sequence
                    if(orderInd[w2[j]] < orderInd[w1[j]]): # the sequence is not valid in the condition
                        return False
                    break
        return True
