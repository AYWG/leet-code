/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

---

- Before applying binary search on a row, need to first identify which row could conceivably have the target
- Choose row by doing:
    - look at first element.
        - target < first element? Can't be in the row. Search in previous rows.
        - target >= first element? 
            - target <= last element?
                OK. Now do binary search on the row like normal.
            - else, we search in next rows.


*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L = 0;
        int R = matrix.size() - 1;

        while (L <= R) {
            int mid = L + (R - L) / 2;

            vector<int> midRow = matrix[mid];

            if (!midRow.size()) {
                return false;
            }

            int first = midRow[0];

            if (target < first) {
                R = mid - 1;
            }
            else {
                int last = midRow[midRow.size() - 1];
                if (target <= last) {
                    return searchRow(midRow, target);
                } else {
                    L = mid + 1;
                }
            }
        }
        return false;
    }
    
    bool searchRow(vector<int>& row, int target) {
        int L = 0;
        int R = row.size() - 1;
        
        while (L <= R) {
            int mid = L + (R - L) / 2;
            
            if (row[mid] == target) {
                return true;
            }
            if (row[mid] < target) {
                L = mid + 1;
            }
            if (row[mid] > target) {
                R = mid - 1;
            }
        }
        return false;
    }
};