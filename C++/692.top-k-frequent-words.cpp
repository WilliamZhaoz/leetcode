struct cmp {
    bool operator()(const pair<int, string> &a, const pair<int, string> &b) {
        if (a.first == b.first) {
            int al = a.second.size(), bl = b.second.size(), i = 0, j = 0;
            while (i < al && j < bl) {
                if (a.second[i] != b.second[j]) {
                    return a.second[i] < b.second[j];
                }
                i++; j++;
            }
            return i == al;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto word : words) {
            m[word]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> q;
        for (auto p : m) {
            q.push(pair<int, string>(p.second, p.first));
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<string> res;
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};
