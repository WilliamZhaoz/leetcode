class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int maxv = 0;
        for (auto c : tasks) {
            count[c - 'A']++;
            maxv = max(maxv, count[c - 'A']);
        }
        int maxc = 0;
        for (auto c : count) {
            maxc += c == maxv;
        }
        return max((int)tasks.size(), (maxv - 1) * (n + 1) + maxc);
    }
};