class Solution {
public:
    // version 1: hash table & map(red & black tree)
    /*
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        multimap<int, int> mm;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            mm.insert({it->second, it->first});

        }
        int i = 0;
        auto it = mm.rbegin();
        for (; i < k; i++, it++) {
            res.push_back(it->second);
        }
       
        return res;
    }
    */
    // version 2: hash table & priority_queue
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            q.push({it->second, it->first});

        }
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second);
            q.pop();
        }
       
        return res;
    }
};