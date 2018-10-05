class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, curmax = 0;
        for (int i = 0; i < arr.size(); i++) {
            curmax = max(curmax, arr[i]);
            if (curmax == i) {
                res++;
            }
        }
        return res;
    }
};