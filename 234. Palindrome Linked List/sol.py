# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        fast = head
        slow= head

        while fast and fast.next: # untill fast reached to end
            fast = fast.next.next 
            slow = slow.next

        prev =  None # new pointer
        while slow: # reversing directions of all elements after the slow pointer
            tmp = slow.next
            slow.next = prev
            prev = slow 
            slow = tmp
        
        left, right = head, prev  # left and right to start and end 
        while right:
            if left.val != right.val: # if values don't match up 
                return False 
            ## else keep on moving
            left = left.next 
            right = right.next
        
        return True
