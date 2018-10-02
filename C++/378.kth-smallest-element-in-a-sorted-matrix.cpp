// version 1 : max heap (priority_queue)
/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                q.push(matrix[i][j]);
                if (q.size() > k) {
                    q.pop();
                }
            }
        }
        return q.top();
    }
};
*/

// version 2 : max heap (by myself)
/*
class Solution {
public:
    void q_push(vector<int> &q, int x) {
        q.push_back(x);   
        int root = q.size() / 2 - 1;
        for (int i = root; i >= 0; i = (i - 1) / 2) {
            adjust(q, i); 
            if (i == 0) {
                break;
            }
        }
    }
    void q_pop(vector<int> &q) {
        swap(q[0], q[q.size() - 1]);
        q.pop_back();
        adjust(q, 0);
    }
    void adjust(vector<int> &q, int root) {
        int left = root * 2 + 1, right = left + 1, tag = left;
        if (left >= q.size()) {
            return;
        }
        if (right < q.size()) {
            tag = q[left] > q[right] ? left : right;
        }
        if (q[tag] > q[root]) {
            swap(q[tag], q[root]);
            adjust(q, tag);
        }
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> q;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                q_push(q, matrix[i][j]);
                if (q.size() > k) {
                    q_pop(q);
                }
            }
        }
        return q[0];
    }
};
*/
// version 3: binary search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), start = matrix[0][0], end = matrix[m - 1][n - 1];
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int cnt = helper(matrix, mid);
            if (cnt < k) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        int cnt = helper(matrix, start);
        if (cnt >= k) { // use >= but not ==, because there a case not ascending ([[1, 2],[1, 3]])
            return start;
        }
        return end;
        
        // return start;
    }
    int helper(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), i = m - 1, j = 0, res = 0;
        while (i >= 0 && j < m) {
            if (matrix[i][j] <= target) {
                res += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return res; 
    }
};

