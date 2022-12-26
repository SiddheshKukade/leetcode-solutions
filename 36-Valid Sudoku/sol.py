class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # just check each row and col doesn't have duplicates.
        # also check eack 3x3 col
        cols = collections.defaultdict(set)
        rows=  collections.defaultdict(set)
        squares = collections.defaultdict(set) # key = (r/3, c /3)
        for r in range(9):
            for c in range(9):
                if board[r][c] ==".":
                    continue
                if(board[r][c] in rows[r] or 
                   board[r][c] in cols[c] or
                   board[r][c] in squares[(r//3, c//3)]): # (r//3, c//3) Works like a index
                   return False
                cols[c].add(board[r][c]) #each time we found new add to the column 
                rows[r].add(board[r][c]) # add to the row
                squares[(r//3, c//3)].add(board[r][c])
        return True
