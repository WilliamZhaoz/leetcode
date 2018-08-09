// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        int preres = 0;
        for (int i = 1; i < n; i++) {
            if (knows(res, i)) {
                preres = res;
                res = i;
            }
        }
        for (int i = 0; i < res; i++) {
            if ((knows(res, i)) || (i != preres && !knows(i, res))) {
                return -1;
            }
        }
        for (int i = res + 1; i < n; i++) {
            if (!knows(i, res)) {
                return -1;
            }
        }
        return res;
    }
};