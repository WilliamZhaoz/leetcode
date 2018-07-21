/*
class Solution {
public:
    bool isValid(string s) {
        stack<char> ms;
        for (int i = 0; i < s.size(); i++) {
            if (ms.empty()) {
                ms.push(s[i]);
                continue;
            }
            if ((ms.top() == '(' && s[i] == ')') || (ms.top() == '[' && s[i] == ']') || (ms.top() == '{' && s[i] == '}')) {
                ms.pop();
            } else {
                ms.push(s[i]);
            }
        }
        return ms.empty();
    }
};
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') parentheses.push(s[i]);
            else {
                if (parentheses.empty()) return false;
                if (s[i] == ')' && parentheses.top() != '(') return false;
                if (s[i] == ']' && parentheses.top() != '[') return false;
                if (s[i] == '}' && parentheses.top() != '{') return false;
                parentheses.pop();
            }
        }
        return parentheses.empty();
    }
};