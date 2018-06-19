class Solution {
public:
    string getPermutation(int n, int k) {
        string res, s;
        int help = 1, index;
        for (int i = 1; i <= n; i++) {
            help *= i;
            s += to_string(i);
        }
        help /= n;
        k -= 1;
        for (int i = n - 1; i > 0; i--) {
            index = k / help;
            k = k % help;
            help /= i;
            res += s[index];
            s.erase(index, 1);
        }
        res += s;
        return res;
        /*
        for case : n = 4, k = 23
                i   k   help    index   s       res
        init    3   22  6               1234    
                2   4   2       3       123     4
                1   0   1       2       12      43
                0   1   1       0       2       431
        end                                     4312
        */
        
    }
};