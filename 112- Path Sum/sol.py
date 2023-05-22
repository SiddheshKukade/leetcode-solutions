# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        #         //traverse the tree from root to leaf and check if targetSum is possible for the comibnations or not.
        # //Performing Inorder traversal recursively.
        # //maintain currsum and check it with target once the leaf is reached 
        def dfs(node, curSum):
            if not node:
                return False
            
            curSum += node.val #updating the cursum
            if not node.left and not node.right: #  if reached to the leaf node.
                return curSum == targetSum # the return the truth 
            #  else keep checking for left and right
            return dfs(node.left, curSum) or dfs(node.right, curSum)
        
        return dfs(root, 0 )
