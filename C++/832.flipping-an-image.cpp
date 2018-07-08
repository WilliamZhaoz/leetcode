class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int left = 0, right = A[0].size();
        for (int i = 0; i < A.size(); i++) {
            left = 0; right = A[0].size() - 1;
            while (left < right) {
                A[i][left] ^= A[i][right];
                A[i][right] ^= A[i][left];
                A[i][left] ^= A[i][right];
                A[i][left] ^= 1;
                A[i][right] ^= 1;
                left++; right--;
            }
            if (A[0].size() % 2 != 0) {
                A[i][A[0].size() / 2] ^= 1;
            }
        }
        return A;
    }
};