class Solution {
public:
    int hIndex(vector<int>& citations) {
        // version 1 :
        /*
        int res = 0;
        for (int i = citations.size() - 1; i >= 0; i--) {
            res++;
            if (citations[i] < citations.size() - i) {
                return res - 1;
            } 
        }
        return res;
        */
        // version 2 : bs
        int len = citations.size(), left = 0, right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] == len - mid) return len - mid;
            else if (citations[mid] > len - mid) right = mid - 1;
            else left = mid + 1;
        }
        return len - left;
    }
};