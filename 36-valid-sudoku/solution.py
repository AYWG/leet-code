class Solution(object):
    """
    Validation checks:
        - Rows
        - Columns
        - Sub-boxes
        
    Thoughts:
        - Checking for rows is easy!
        - Checking for columns and sub-boxes will require some thinking;
        how to extract the columns and subboxes from the grid?
        
        How to check for repetition?
        - Let's say we have an array of flags that are initially 0
        - Once we see a number, then we set the flag
        - If we see a number and the flag is already set, we have repetition
    
    """
    def isValidRow(self, board, rowIndex):
        row = board[rowIndex]
        return self.isValidCells(row)
    
    def isValidCol(self, board, colIndex):
        col = map(lambda x: x[colIndex], board)
        return self.isValidCells(col)
    
    def isValidSubBox(self, board, subBoxIndex):
        subBox = []
        # Extract sub box from board
        # Row: 0 (0, 1, 2), 3, 6
        if subBoxIndex <= 2:
            row = 0
        elif subBoxIndex <= 5:
            row = 3
        else:
            row = 6
        
        if subBoxIndex % 3 == 0:
            col = 0
        elif subBoxIndex % 3 == 1:
            col = 3
        else:
            col = 6
            
        for i in range(3):
            for j in range(3):
                subBox.append(board[row + i][col + j])
                
        return self.isValidCells(subBox)
        
        
    def isValidCells(self, cells):
        cellsWithEmptyRemoved = [cell for cell in cells if cell != "."]
        cellsWithEmptyRemovedSet = set(cellsWithEmptyRemoved)
        return len(cellsWithEmptyRemoved) == len(cellsWithEmptyRemovedSet)
    
    
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(9):
            if not self.isValidRow(board, i):
                return False
            
            if not self.isValidCol(board, i):
                return False
            
            if not self.isValidSubBox(board, i):
                return False
        
        return True