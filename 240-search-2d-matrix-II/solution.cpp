/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

---

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Target = 5

What's the most efficient way to search?
- just looking at first element of rows, there would be 3 potential candidates (the first 3)
- just looking at columns, there would be 2 potential candidates (the first 2)

Target = 20
- just looking at first element of rows, there would be 5 potential candidates
- just looking at columns, there would be 5 potential candidates

-> just looking at first element is insufficient. Need different check(s).

- Check last element as well?
    - If done, target = 20 would lead to 4 possible columns, and 3 possible rows

In the above matrix, 20 could replace: 17, 18, 19, 21
    - If I were to pick the middle row and DO BS, I wouldn't find it.
    - Then going "left" or "right" would be valid candidates, since 20 could be where the 19 is or where the 17 is

if I look along the diagonal, I can make some deductions about where the target could be.
    - E.g. if I look at 17, I know that my target of 20 can't be in any of the spaces within the submatrix defined by 17 (where 17 is the bottom right corner of it); therefore, the only valid searches would be in the last row and last column.

How would this strategy work with a smaller target (e.g. 5)?
    - Keep going along the diagonal until you either find it (it's on the diagonal) or you find a number that is strictly less than target - then you know it can't be within the submatrix, so you go back up to the last diagonal value and search the corresponding row/col.

Now, perfect diagonal can't be assumed, since matrix is arbitrary m x n. Does this still work?

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 18, 24],
  [17, 21, 23, 26, 30]
]
(same as above, but 18 and 17 swapped. Still valid matriox, but 17 would be outside the "submatrix" defined by 18)

Assume matrix :

[1,   4,  7, 11, 15, 16],
[2,   5,  8, 12, 19, 20],
[3,   6,  9, 16, 22, 23],

Target is 15. 

Assume initial mid is 12. See that mid < target.
Deduce that:
    - target is either in last 2 cols, or mid is in last col

Target is 5.

Assume initial mid is 12. See that mid > target.


[1 4    7]
[2 5    8]
[3 6    9]
[11 12 16]
[15 17 18]

Target is 15.

Assume initial mid is 6. see that mid < target.
Deduce that:
    - target is in last two rows or last col

Algorithm:
    - traverse top left to bottom right diagonal
        - if diagonal < target, keep going
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = 0;
        
        int nrows = matrix.size();
        if (nrows == 0) return false;
        int ncols = matrix[0].size();
        if (ncols == 0) return false;
        while (row < nrows || col < ncols) {
            int actualRow = row < nrows ? row : nrows - 1;
            int actualCol = col < ncols ? col : ncols - 1;
            int diagonalVal = matrix[actualRow][actualCol];

            if (diagonalVal == target) return true;
            if (diagonalVal < target) {
                if (row < nrows) row++;
                if (col < ncols) col++;
                continue;
            }
            bool isFound = searchRow(matrix[actualRow], target) || searchCol(matrix, actualCol, target);
            if (isFound) return true;
            
            if (row < nrows) row++;
            if (col < ncols) col++;
        }
        return false;
        
    }

    bool searchRow(vector<int>& row, int target) {
        int L = 0;
        int R = row.size() - 1;

        while (L <= R) {
            int mid = L + (R - L) / 2;
            if (row[mid] == target) return true;

            if (row[mid] < target) L = mid + 1;
            else R = mid - 1;
        }
        return false;
    }

    bool searchCol(vector<vector<int>>& matrix, int col, int target) {
        int top = 0;
        int bot = matrix.size() - 1;

        while (top <= bot) {
            int mid = top + (bot - top) / 2;
            if (matrix[mid][col] == target) return true;

            if (matrix[mid][col] < target) top = mid + 1;
            else bot = mid - 1;
        }
        return false;
    }

};