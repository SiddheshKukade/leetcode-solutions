class Solution:
    def reverseBits(self, n: int) -> int:
    #         //logic and with 1 gives the same output of the operand.
    #  //    left shift 
    #  // 10 << 1 => 01
    #  // Bit Manupulation 
    #  // Divide and Conquer
        res = 0
        for i in range(32):
            bit =(n>>i) & 1
            res = res | (bit << (31-i)) # left shifting all of the bits
        return res
        
