/*
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    
    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }
    
    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
};
*/

class Solution {
    
    public Node construct(int[][] grid) {
        return construct(0, 0, grid, grid.length);
    }
    
    private Node construct(int x, int y, int[][] grid, int length){
        
        if( length == 1 ) {
            return new Node(grid[x][y] == 1, true, null, null, null, null);
        }
        
        Node topLeft = construct(x, y, grid, length/2);//row=x col = y
        Node topRight = construct(x, y+length/2, grid, length/2);//row = x col = y+length/2
        Node bottomLeft = construct(x+length/2, y, grid, length/2);//row = x+length/2 col = y
        Node bottomRight = construct(x+length/2, y+length/2, grid, length/2);//row = x+length/2 col = y+length/2
            
        Node n = new Node();
        
        if( topLeft.val == topRight.val && topLeft.val == bottomLeft.val && topLeft.val == bottomRight.val &&
          topLeft.isLeaf && topRight.isLeaf && bottomLeft.isLeaf && bottomRight.isLeaf ){//If leafs with same value only then combine
            n.val = topLeft.val;
            n.isLeaf = true;
        }else{
            n.topLeft = topLeft;
            n.topRight = topRight;
            n.bottomLeft = bottomLeft;
            n.bottomRight = bottomRight;   
        }
        
        return n;
    } 

}
