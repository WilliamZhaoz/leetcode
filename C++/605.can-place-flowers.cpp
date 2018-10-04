class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int res = 0, pre = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 && (pre == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                res++;
                pre = 1;
            } else {
                pre = flowerbed[i];
            }
        }
        return res >= n;
    }
};