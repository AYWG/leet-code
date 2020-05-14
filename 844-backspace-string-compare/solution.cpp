class Solution {
public:
    bool backspaceCompare(string S, string T) {
        std::stack<char> S_stack;
        std::stack<char> T_stack;
        
        for (char c: S) {
            if (c == '#') {
                if (!S_stack.empty()) {
                    S_stack.pop();                
                }
            } else {
                S_stack.push(c);
            }
        }
        
        for (const char &c: T) {
            if (c == '#') {
                if (!T_stack.empty()) {
                    T_stack.pop();                
                }
            } else {
                T_stack.push(c);
            }
        }
        
        if (S_stack.size() != T_stack.size()) return false;
        
        while (!S_stack.empty() && !T_stack.empty()) {
            if (S_stack.top() != T_stack.top()) {
                return false;
            }
            S_stack.pop();
            T_stack.pop();
        }
        return true;
    }
};