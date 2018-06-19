class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        int f[n + 1];
        bool isPalin[n][n];
        
        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
            if (i + 1 < n) {
                isPalin[i][i + 1] = (s[i] == s[i + 1]);
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                isPalin[i][j] = isPalin[i + 1][j - 1] && (s[i] == s[j]);
            }
        }
        f[0] = -1; // this option is to adjust to the case in which all the elements are same.
        for (int i = 1; i <= n; i++) {
            f[i] = i - 1;
            for (int j = 0; j < i; j++) {
                if (isPalin[j][i - 1]) {
                    f[i] = min(f[i], f[j] + 1);
                }
            }
        }
        return f[n];
    }
};