// Time taken: 56m 53s

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        int resultMaxLen = n - k;
        
        string result = "0";
        int startIndex = 0;
        int endIndex;
        char minDigit = '9';
        int minDigitIndex = startIndex;
        
        // Done once we've gathered all possible digits for result
        for (int i = 0; i < resultMaxLen; i++) {
            endIndex = n - (resultMaxLen - i);
            
            for (int j = startIndex; j <= endIndex; j++) {
                // Find min digit to use for result
                if (num[j] < minDigit) {
                    minDigit = num[j];
                    minDigitIndex = j;
                }
            }
            startIndex = minDigitIndex + 1;
            result += minDigit;
            // reset min
            minDigit = '9';
            minDigitIndex = startIndex;
        }
        
        // Deal with leading zeroes
        while (result.size() > 1) {
            if (result[0] == '0') {
                result.erase(0, 1);
            } else {
                break;
            }
        }
        return result;
    }
};