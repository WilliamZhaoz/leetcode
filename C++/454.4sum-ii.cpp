class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // hash, version 1 : 1 map
        /*
        int res = 0, n = A.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ++m[A[i] + B[j]];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int target = -(C[i] + D[j]);
                res += m[target];
            }
        }
        return res;
        */
        // hash, version 2 : 2 maps
        int res = 0, n = A.size();
        unordered_map<int, int> m1, m2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ++m1[A[i] + B[j]];
                ++m2[C[i] + D[j]];
            }
        }
        for (auto i : m1) res += i.second * m2[-i.first];
        return res;
    }
};