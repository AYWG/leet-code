/*

Goal: longest palindromic substring.

Notes:
- Given some palindromic substring in s, can check if it can be extended by checking one character before and one character after and comparing the two for equality.
    - Would start at some center and continue extending until can't
    
- How would we find the longest one?

Algorithm:

For every character in s
    - Start building palindrome as above
    - Each time we extend, compare length to longest length and update it larger

Problem: even length palindromes (e.g. cbbd)
Solution: when starting a new palindrome on a given character, first extend it rightwards to include any consecutive duplicates. 
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string currentLongestPalindrome = "";
        
        for (int i = 0; i < s.length(); i++) {
            int left = i - 1;
            string currentPalindrome;
            currentPalindrome.insert(0, 1, s[i]);
            
            // Handle situations where there are an even number of consecutive duplicates of a char when the
            // palindrome is initially started
            while (i + 1 < s.length() && s[i] == s[i + 1]) {
                currentPalindrome.insert(0, 1, s[i]);
                i++;
            }
            if (currentPalindrome.length() > currentLongestPalindrome.length()) {
                currentLongestPalindrome = currentPalindrome;
            }
            
            int right = i + 1;
            while (left >= 0 && right < s.length()) {
                if (s[left] == s[right]) {
                    currentPalindrome.insert(0, 1, s[left]);
                    currentPalindrome.push_back(s[right]);
                    
                    if (currentPalindrome.length() > currentLongestPalindrome.length()) {
                        currentLongestPalindrome = currentPalindrome;
                    }
                    left--;
                    right++;
                }
                else {
                    break;
                }
            }
            
        }
        return currentLongestPalindrome;
    }
};