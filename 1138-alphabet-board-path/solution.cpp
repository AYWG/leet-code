class Solution {
public:
    string alphabetBoardPath(string target) {
        int curr_row_i = 0, curr_col_i = 0;
        string output = "";
        for (int target_i = 0; target_i < target.size(); target_i++) {
            int alpha_i = target[target_i] - 'a';
            int target_row_i = alpha_i / 5;
            int target_col_i = alpha_i % 5;
            int delta_row_i = target_row_i - curr_row_i;
            int delta_col_i = target_col_i - curr_col_i;

            if (delta_row_i >= 0) {
                // Down
                // Edge case: target is z and curr_col_i != 0 -> can't immediately go all the way to the last row
                int num_moves_down = delta_row_i;
                if (target_row_i == 5) {
                    num_moves_down--;
                }
                for(int j = 0; j < num_moves_down; j++) output += "D";
            } else {
                // Up
                for(int j = 0; j < (-1 * delta_row_i); j++) output += "U";
            }

            if (delta_col_i >= 0) {
                // Right
                for(int j = 0; j < delta_col_i; j++) output += "R";
            } else {
                // Left
                for(int j = 0; j < (-1 * delta_col_i); j++) output += "L";
            }
            if (target_row_i == 5 && delta_row_i > 0) {
                output += "D";
            }

            curr_row_i += delta_row_i;
            curr_col_i += delta_col_i;
            output += "!";
        }
        return output;
    }
};


