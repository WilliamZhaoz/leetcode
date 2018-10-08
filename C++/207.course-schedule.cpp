class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, int> count;
        for(auto p : prerequisites) {
            count[p.second]++;
        }
        while (1) {   
            bool f = false;
            for (int j = 0; j < prerequisites.size(); j++) {
                if (count.count(prerequisites[j].first) == 0 || count.count(prerequisites[j].second) == 0) {
                    f = true;
                    count[prerequisites[j].second]--;
                    if (count[prerequisites[j].second] == 0) {
                        count.erase(prerequisites[j].second);
                    }
                    prerequisites.erase(prerequisites.begin() + j--);
                }
            }
            if (!f && !prerequisites.empty()) {
                return false;
            }
            if (prerequisites.empty()) {
                return true;
            }
        }
        return true;
        
    }
};
