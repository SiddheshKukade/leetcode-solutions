
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, s: Optional[TreeNode], t: Optional[TreeNode]) -> bool:
        # check if a tree is subtree of another
            # Two functions
            # 1. Sametree - just checks the left and right values
            # 2. isSubtree
            #edge cases - (questions to be asked to interviwer)
                # Both trees are null -- they would be considerd as the same
                # If one of the has a extra node (ex2) - Then it's false
                # Is a NULL subtree a subtree of another - Yes it is 
        if not t: return True
        if not s and t: return False
        if self.sameTree(s,t):
            return True
        return self.isSubtree(s.left, t) or self.isSubtree(s.right, t)

    def sameTree(self ,s,t) -> bool:
        if not s and not t: # if t,s are null
            return True
        if s and t and s.val == t.val:
            #now compare the rest of subtrees
            return self.sameTree(s.left, t.left) and self.sameTree(s.right, t.right)
        return False



        
