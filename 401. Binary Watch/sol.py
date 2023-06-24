class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        #    // return all possible times the watch could represent. You may return the answer in any order.
        output = []
        for h in range(12):
            for m in range(60) :
                temp= bin(h)+bin(m)
                if temp.count("1") == turnedOn:
                    time = '%d:%02d' % (h,m)
                    output.append(time)
        return output
