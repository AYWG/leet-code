/*

Algorithm:

- For each number 1-9, retrieve a vector of pairs representing the coordinates of all appearances of that number in the board.
- Then, for each number, we examine the coordinates to check for validity. We do this by verifying no two coordinates share the same:
    1. Row
    2. Col
    3. Box

    We use a hashtable for each criteria.
*/

class Solution {
public:
int getBoxNum(int row, int col) {
    return 3 * (row / 3) + col / 3;
}

bool isValidSudokuCoords(vector<pair<int, int>>& coords) {
    unordered_map<int, int> rowTable;
    unordered_map<int, int> colTable;
    unordered_map<int, int> boxTable;

    for (auto coord : coords) {
        int row = coord.first;
        int col = coord.second;
        int box = getBoxNum(row, col);

        rowTable[row]++;
        colTable[col]++;
        boxTable[box]++;

        if (rowTable[row] > 1 ||  colTable[col] > 1 || boxTable[box] > 1) return false;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<pair<int,int>>> numberCoords(9);

    // Store coords of all non-empty cells
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != '.') {
                int number = board[i][j] - '0';
                numberCoords[number - 1].push_back(make_pair(i, j));
            }
        }
    }

    for (auto numberCoord : numberCoords) {
        if (!isValidSudokuCoords(numberCoord)) return false;
    }
    return true;
}
};