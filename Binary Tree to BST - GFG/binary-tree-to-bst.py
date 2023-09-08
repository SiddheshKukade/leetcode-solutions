from collections import deque

class Solution:
    def level_order_traversal(self, root):
        queue, result, position, length = deque(), [], 0, 1
        queue.append(root)

        while position < length:
            current_node = queue[position]
            result.append(current_node.data)

            if current_node.left:
                queue.append(current_node.left)
                length += 1

            if current_node.right:
                queue.append(current_node.right)
                length += 1

            position += 1

        return sorted(result)

    def convert_to_bst(self, root, values):
        if root is None:
            return

        self.convert_to_bst(root.left, values)
        root.data = values.pop(0)
        self.convert_to_bst(root.right, values)

    def binaryTreeToBST(self, root):
        inorder_values = self.level_order_traversal(root)
        self.convert_to_bst(root, inorder_values)
        return root
#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import deque
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

# Function to Build Tree   
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):           
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root

def printInorder(root): 
    if root is None: 
        return
    printInorder(root.left) 
    print (root.data, end=' ')  
    printInorder(root.right) 

if __name__=="__main__":
    t=int(input())
    for _ in range(0,t):
        s=input()
        root=buildTree(s)
        Solution().binaryTreeToBST(root)
        printInorder(root)
        print()
# } Driver Code Ends