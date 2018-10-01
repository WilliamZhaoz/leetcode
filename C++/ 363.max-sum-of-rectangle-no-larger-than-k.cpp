// version 1: time complexity O(n^4)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sums(m + 1, vector<int>(n + 1, 0));
        int tmp = 0;
        for (int i = 1; i <= m; i++) {
            tmp += matrix[i - 1][0];
            sums[i][1] = tmp;
        }
        tmp = 0;
        for (int i = 1; i <= n; i++) {
            tmp += matrix[0][i - 1];
            sums[1][i] = tmp;
        }
        
        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                sums[i][j] = matrix[i - 1][j - 1] + sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            }
        }
        /*
        for (auto r : sums) {
            for (auto c : r) {
                cout<<c<<" ";
            }
            cout<<endl;
        }
        */
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                for (int p = i + 1; p <= m; p++) {
                    for (int q = j + 1; q <= n; q++) {
                        int cur = sums[p][q] - sums[p][j] - sums[i][q] + sums[i][j];
                        if (cur <= k) {
                            // cout<<i<<" "<<j<<" "<<p<<" "<<q<<" "<<cur<<endl;
                            res = max(res, cur);
                        }
                    }
                }
            }
        }
        return res;
    }
};