/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // version 1: calculate the depth firstly, then sum.
    /*
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int cur = 1, depth = 1;
        getDepth(nestedList, cur, depth);
        return helper(nestedList, depth);
    }
    void getDepth(vector<NestedInteger> &nestedList, int cur, int &depth) {
        depth = max(depth, cur);
        for (auto nl : nestedList) {
            if (!nl.isInteger()) {
                getDepth(nl.getList(), cur + 1, depth);
            }
        }
    }
    int helper(vector<NestedInteger> &nestedList, int depth) {
        int res = 0;
        for (auto nl : nestedList) {
            res += nl.isInteger() ? depth * nl.getInteger() : helper(nl.getList(), depth - 1);
        }
        return res;
    }
    */
    // version 2: leaf level add repeatedly, BFS
    /*
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int unweighted = 0, weighted = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nextLevel;
            for (auto a : nestedList) {
                if (a.isInteger()) {
                    unweighted += a.getInteger();
                } else {
                    nextLevel.insert(nextLevel.end(), a.getList().begin(), a.getList().end());
                }
            }
            weighted += unweighted;
            nestedList = nextLevel;
        }
        return weighted;
    }
    */
    // version 3: BFS
     int depthSumInverse(vector<NestedInteger>& nestedList) {
        int unweighted = 0, weighted = 0;
        while (!nestedList.empty()) {
            int s = nestedList.size();
            for (int i = 0; i < s; i++) {
                if (nestedList[0].isInteger()) {
                    unweighted += nestedList[0].getInteger();
                } else {
                    nestedList.insert(nestedList.end(), nestedList[0].getList().begin(), nestedList[0].getList().end());
                }
                nestedList.erase(nestedList.begin());
            }
            weighted += unweighted;
        }
        return weighted;
    }
};