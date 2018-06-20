class Solution {
public:
    /*
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> com;
        vector<bool> visited(candidates.size(), false);
        if (candidates.empty()) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        helper(res, com, candidates, visited, target, 0);
        return res;
    }
    void helper(vector<vector<int>> &res, vector<int> &com, vector<int> &candidates, vector<bool> &visited, int target, int start) {
        if (target <= 0) {
            if (target == 0) {
                res.push_back(com);
            }
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
        		// if candidates[i] == candidates[i - 1], only when visited[i - 1] == true, candidates[i] can add or not, in this way, the same number only add
        		// different times but no permutations.
            if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) { 
                continue;
            }
            visited[i] = true;
            target -= candidates[i];
            com.push_back(candidates[i]);
            helper(res, com, candidates, visited, target, i + 1);
            com.pop_back();
            target += candidates[i];
            visited[i] = false;
        }
    }
    */
    // version 2 non-recursive version
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		// write your code here
        sort(num.begin(), num.end());
        vector<int> stack, rec; int sum=0, cur=0;
        vector<vector<int> > ans;
        while (cur<num.size() && num[cur]+sum<=target) {
			stack.push_back(num[cur]);
			rec.push_back(cur);
			sum+=num[cur++];
		}
		if (sum==target) ans.push_back(stack);
		while (rec.size()!=0) {
			cur=rec.back(); int x=num[cur];
			sum-=x; stack.pop_back(); rec.pop_back();
			for (++cur; cur<num.size(); ++cur)
				if (num[cur]!=x || sum+num[cur]>target) break;
			if (cur<num.size() && num[cur]!=x)
				while (cur<num.size() && num[cur]+sum<=target) {
					stack.push_back(num[cur]);
					rec.push_back(cur);
					sum+=num[cur++];
				}
			if (sum==target) ans.push_back(stack);
		}
		return ans;
    }
};