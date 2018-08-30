class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s, ress;
        for (int i = 0; i < nums1.size(); i++) {
            s.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (s.count(nums2[i])) {
                ress.insert(nums2[i]);
            }
        }
        return vector<int>(ress.begin(), ress.end());
    }
};