class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:  
        res= [1] * (len(nums)) # ans array contains alll 1s
        prefix = 1 
        for i in range(len(nums)):
            res[i] = prefix # insert perfix in i 
            prefix *= nums[i] # multiply current i with prefix and store in prefix
        postfix =1
        for i in range(len(nums)-1, -1 , -1):
            res[i] *= postfix # reversing and storing the postfix
            postfix *= nums[i];  # multiply the number and store it as postfix
        return res # Finally result will have  first prefix values then multiplied by the postfix values so all the possible multiplications will be present
