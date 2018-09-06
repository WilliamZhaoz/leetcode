class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        if ((l1 + l2) % 2) {
            return findKth(nums1, nums2, (l1 + l2 + 1) / 2); 
        }
        cout<<findKth(nums1, nums2, (l1 + l2) / 2)<<" "<<findKth(nums1, nums2, (l1 + l2) / 2 + 1)<<endl;
        return (findKth(nums1, nums2, (l1 + l2) / 2) + findKth(nums1, nums2, (l1 + l2) / 2 + 1)) / 2.0; 
    }
    int findKth(vector<int> &nums1, vector<int> &nums2, int k) {
        if (nums1.empty()) {
            return nums2[k - 1];
        }
        if (nums2.empty()) {
            return nums1[k - 1];
        }
        if (k == 1) {
            return min(nums1[0], nums2[0]);
        }
        int t1 = min(int(nums1.size()), k / 2), t2 = min(int(nums2.size()), k / 2);
        if (nums1[t1 - 1] > nums2[t2 - 1]) {
            vector<int> newv(nums2.begin() + t2, nums2.end());
            return findKth(nums1, newv, k - t2);
        } else {
            vector<int> newv(nums1.begin() + t1, nums1.end());
            return findKth(newv, nums2, k - t1);
        }
    }
};