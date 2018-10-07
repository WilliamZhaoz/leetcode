class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        if (path.empty()) {
            return res;
        }
        stack<char> s;
        s.push('/');
        for (int i = 0; i < path.size(); i++) {
            if (!s.empty()) {
                char tmp = s.top();
                if (tmp == '.' && path[i] == '.') {
                    int c = 2;
                    while (c) {
                        tmp = s.top();
                        s.pop();
                        
                        if (tmp == '/') {
                            c--;
                        }
                        if (s.empty()) {
                            s.push('/');
                        }
                    }
                    
                    continue;
                }
                if (tmp == '.' && path[i] == '/') {
                    s.pop();
                    continue;
                }
                if (tmp == '/' && path[i] == '/') {
                    continue;
                }
            }
            
        
            s.push(path[i]);
        }
        if (s.top() == '.') {
            s.pop();
        }
        if (s.top() == '/' && s.size() > 1) {
            s.pop();
        }
        
        while (!s.empty()) {
            res = s.top() + res;
            s.pop();
        }
        return res;
    }
};