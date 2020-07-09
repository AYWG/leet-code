/*

1. Iterate through matrix.
    - if 0, keep going
    - if 1, do the following:
        - set initial area to 1
        - check adj element to right, adj element to bottom, and diagonal to see if they are 1s
            - if yes, set area to 4, and repeat
            - if not, stop and update maximal area if the new area is bigger than the current maximum.

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxArea = 0;
        
        int nrows = matrix.size();
        
        if (nrows == 0) {
            return 0;
        }
        
        int ncols = matrix[0].size();
        
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                if (matrix[i][j] == '1') {
                    maxArea = max(maxArea, getSquareArea(matrix, i, j));
                }
            }
        }
        
        return maxArea;
    }
    
    int getSquareArea(vector<vector<char>>& matrix, int i, int j) {
        int nrows = matrix.size();
        int ncols = matrix[0].size();
        
        int squareLength = 1;
        
        //Stop when bigger square would be beyond matrix bounds or if added elements have 0s
        while (true) {
            bool zeroFound = false;
            
            if (i + squareLength >= nrows || j + squareLength >= ncols) {
                break;
            }
            
            for (int row = i; row <= i + squareLength; row++) {
                if (matrix[row][j + squareLength] == '0') {
                    // zero found
                    zeroFound = true;
                }
            }
            
            for (int col = j; col <= j + squareLength - 1; col++) {
                if (matrix[i + squareLength][col] == '0') {
                    // zero found
                    zeroFound = true;
                }
            }
            
            if (zeroFound) {
                break;
            }
            
            squareLength++;
        }
        
        return squareLength * squareLength;
    }
};