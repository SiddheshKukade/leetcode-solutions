"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        oldToNew={} #hashmap
        def dfs(node):
            if node in oldToNew: #if clone already there
                return oldToNew[node]
            # create a new copy of current node
            copy = Node(node.val) 
            oldToNew[node] = copy
            for nei in node.neighbors:
                copy.neighbors.append(dfs(nei))
            return copy
        return dfs(node)if node else None  # returning any node after the deep copy is created    
