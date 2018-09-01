class Solution {
public:
    // version 1 : recursive version 1
    /*
    double myPow(double x, int n) {
        return n > 0 ? pow(x, n) : 1.0 / pow(x, -n);
    }
    double pow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double half = pow(x, n / 2);
        return n % 2 ? half * half * x : half * half;         
    }
    */
    // version 2 : recursive version 2
    /*
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double half = pow(x, n / 2);
        return n % 2 > 0 ? half * half * x : n % 2 == 0 ? half * half : half * half / x; 
    }
    */ 
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            if (i % 2 != 0) {
                res *= x;
            }
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};