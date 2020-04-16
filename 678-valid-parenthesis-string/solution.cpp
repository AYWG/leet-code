/*

Time for 1st attempt: ~54 minutes

Key points:
    - The stars can be used to balance out extra parentheses, but this depends on where the stars are positioned relative to any extra parentheses in the string
    - Thus, we need to keep track of indices of stars and open parentheses as we iterate through the string
    - We don't need to keep track of indices of close parentheses because they either immediately match up with an open parenthesis/star or are in a position that automatically invalidates the string

*/

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stars;
        stack<int> extraOpens;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                extraOpens.push(i);
            }
            else if (s[i] == '*') {
                stars.push(i);
            }
            else {
                if (!extraOpens.empty()) {
                    extraOpens.pop();
                }
                else if (!stars.empty()) {
                    stars.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        while (!extraOpens.empty()) {
            if (stars.empty()) {
                return false;
            }
            
            int starInd = stars.top();
            
            if (starInd < extraOpens.top()) {
                return false;
            }
            
            stars.pop();
            extraOpens.pop();
        }
        
        return true;
    }
};