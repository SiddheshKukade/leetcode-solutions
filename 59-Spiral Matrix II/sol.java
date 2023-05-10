class Solution {
    public int[][] generateMatrix(int n) {
        //  int r1=0, r2=n-1;
        // int c1=0, c2=n-1;
        // int[][]arr = new int [n][n];
        // int val =1 ;
        // while(r1<=r2 && c1<=c2){
        //     // left to right
        //     for(int c=c1; c<=c2;c++) arr[r1][c]=val++;
        //     // move  down
        //     for(int r=r1;r<=r2;r++) arr[r][c2]=val++;
        //     // move right to left
        //     if(r1<r2 && c1<c2){
        //         for(int c=c2-1; c>c1;c--) arr[r2][c]=val++;

        //         // move up
        //         for(int r=r2; r>r1;r--) arr[r][c1]=val++;
        //     }
        // r1++; r2--; c1++; c2--;
        // }
        // return arr;
          int[][] matrix = new int[n][n];
        fillMatrix(matrix, 0, n - 1, 0, n - 1, 1);
        return matrix;
    }
     public  void fillMatrix(int[][] matrix, int top, int bottom, int left, int right, int num) {
        if (top > bottom || left > right) { // unitl we don't overflow
            return;
        }
        for (int i = left; i <= right; i++) { //from left to right
            matrix[top][i] = num;
            num++;
        }
        for (int i = top + 1; i <= bottom; i++) { // from top to bottom
            matrix[i][right] = num;
            num++;
        }
        if (top < bottom && left < right) { // making sure that we are in the square
            for (int i = right - 1; i >= left; i--) { //  from right to left 3rd step
                matrix[bottom][i] = num;
                num++;
            }
            for (int i = bottom - 1; i > top; i--) { // from bottom top 4th step
                matrix[i][left] = num;
                num++;
            }
        }
        fillMatrix(matrix, top + 1, bottom - 1, left + 1, right - 1, num);
     }
}
