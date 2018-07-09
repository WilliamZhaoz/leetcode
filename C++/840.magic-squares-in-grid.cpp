class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        if (grid.size() < 3 || grid[0].size() < 3) {
            return res;
        }
        for (int i = 0; i < grid.size() - 2; i++) {
            for (int j = 0; j < grid[0].size() - 2; j++) {
                bool flag = true;
                for (int m = 0; m < 3; m++) {
                    for (int n = 0; n < 3; n++) {
                        if (grid[i + m][j + n] > 9 || grid[i + m][j + n] < 1) {
                            flag = false;
                        }
                    }
                }
                if (!flag) {
                    continue;
                }
                int l1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                int l2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
                int l3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                int v1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                int v2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
                int v3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
                int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                int d2 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];
                cout<<l1<<l2<<l3<<v1<<v2<<v3<<d1<<d2<<endl;
                cout<<i<<j<<endl;
                if ((l1 == l2) && (l1 == l3) && (l1 == v1) && (l1 == v2) && (l1 == v3) && (l1 == d1) && (l1 == d2)) {
                    res++;
                    cout<<"res++"<<endl;
                    
                }
            }
        }
        return res;
    }
};