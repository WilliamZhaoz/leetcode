class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            m1[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (m1[nums2[i]] > 0) {
                res.push_back(nums2[i]);
                m1[nums2[i]]--;
            }
        }
        return res;
    }
};