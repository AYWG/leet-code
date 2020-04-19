/*

Approach 1: Brute force

Starting from top left, traverse all possible paths going down/right, keeping track of sum
Once path reaches end (bottom right), compare sum to minimum. Update minimum if sum is lower

Potential optimizations:
- After finding sum of one path, any other paths that get to a sum greater than the current min mid-way through can be terminated early

Problems:
    At some point in the grid (let's say somewhere in the middle), that point could have been reached via a number of different paths. Only one particular path is of interest (the one that produced the min sum to get to the point); all other paths are irrelevant, yet in this brute force we continue going along the other paths to get to the end.
    
Approach 2: DP

In general:
    MPS(i, j) = grid[i][j] + min(MPS(i, j - 1), MPS(i - 1, j))
    
Can we use existing grid to store results?
    - Want to know whether or not table result is already computed
    - Idea: store computed MPS as negative result
    - if table lookup results in positive value, we know it hasn't been computed yet

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nrows = grid.size();
        
        if (nrows == 0) return 0;
        
        int ncols = grid[0].size();
        
        return getMPS(grid, nrows - 1, ncols - 1);
        
    }
    
    int getMPS(vector<vector<int>>& grid, int i, int j) {
        // result already computed - stored as negative of the sum
        if (grid[i][j] < 0) {
            return -1 * grid[i][j];
        }
        
        if (i - 1 >= 0 && j - 1 >= 0) {
            int mps = grid[i][j] + min(getMPS(grid, i, j - 1), getMPS(grid, i - 1, j));
            grid[i][j] = -1 * mps;
            return mps;
        }
        if (i - 1 >= 0) {
            int mps = grid[i][j] + getMPS(grid, i - 1, j);
            grid[i][j] = -1 * mps;
            return mps;
        }
        if (j - 1 >= 0) {
            int mps = grid[i][j] + getMPS(grid, i, j - 1);
            grid[i][j] = -1 * mps;
            return mps;
        }
        int mps = grid[i][j];
        return mps;
    }
    

};