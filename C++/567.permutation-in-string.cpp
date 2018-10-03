class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // version 1 : 2 map
        /*
        vector<int> m1(128, 0), m2(128, 0);
        for (auto a : s1) {
            m1[a]++;
        }
        for (int i = 0; i < s2.size(); i++) {
            m2[s2[i]]++;
            if (i - (int)s1.size() >= 0) {
                m2[s2[i - s1.size()]]--;
            }
            if (m1 == m2) {
                return true;
            }
        }
        return false;
        */
        // version 2 : 1 map + 2 pointers
        vector<int> m(128, 0);
        for (auto a : s1) {
            m1[a]++;
        }
        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            if (--m[s2[right] < 0]) {
                while (++m[s2[left++] != 0]) {}
            } else if (right - left + 1 == n1) {
                return true;
            }
            
        }
        return n1 == 0;
    }
};