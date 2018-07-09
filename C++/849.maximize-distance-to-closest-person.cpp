class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0, tmp = 0, left = 0;
        bool nobody = true;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                tmp = 0;
                nobody = false;
            } else {
                if (nobody) {
                    left++;
                }
                tmp++;
                res = max(res, tmp);
            }
        }
        return max(max((res + 1) / 2, tmp), left);
    }
};