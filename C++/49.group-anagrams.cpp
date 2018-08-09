// version 1: brute force version: only use once hash table, the last case TLE.
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<unordered_map<char, int>> vecmap;
        if (strs.empty()) {
            return res;
        }
        res.push_back(vector<string>{strs[0]});
        unordered_map<char, int> fm;
        for (int i = 0; i < strs[0].size(); i++) {
            fm[strs[0][i]]++;
        }
        vecmap.push_back(fm);
        for (int i = 1; i < strs.size(); i++) {
            unordered_map<char, int> tmp;
            for (int p = 0; p < strs[i].size(); p++) {
                tmp[strs[i][p]]++;
            }
            bool find = false;
            for (int j = 0; j < vecmap.size(); j++) {
                if (samemap(tmp, vecmap[j])) {
                    find = true;
                    res[j].push_back(strs[i]);
                    break;
                }
            }
            if (!find) {
                res.push_back(vector<string>{strs[i]});
                vecmap.push_back(tmp);
            }
        }
        return res;
    }
    bool samemap(unordered_map<char, int> &map1, unordered_map<char, int> &map2) {
        auto it1 = map1.begin();
        for (; it1 != map1.end(); it1++) {
            if (map2[it1->first] != it1->second) {
                break;
            }
        }
        auto it2 = map2.begin();
        for (; it2 != map2.end(); it2++) {
            if (map1[it2->first] != it2->second) {
                break;
            }
        }
        return it1 == map1.end() && it2 == map2.end();
    }
};
*/
// version 2: sort and hash table
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string strsorted = strs[i]; 
            sort(strsorted.begin(), strsorted.end());
            m[strsorted].push_back(strs[i]);
        }
        for (auto p : m) {
            res.push_back(p.second);
        }
        return res;         
    }
};
*/
// version 3: use twice hash table
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> hash(26, 0);
            for (auto c : strs[i]) {
                hash[c - 'a']++;
            }
            string k = "";
            for (auto c : hash) {
                k += to_string(c) + "|";
            }
            m[k].push_back(strs[i]);
        }
        for (auto p : m) {
            res.push_back(p.second);
        }
        return res;
    }
};