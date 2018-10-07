/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct cmp {
         bool operator() (ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };
   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // version 1 : divide % conquer
        /*
        if (lists.empty()) {
            return NULL;
        }
        return divideConquer(lists, 0, lists.size() - 1);        
    }
    ListNode* divideConquer(vector<ListNode*> &lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        int mid = start + (end - start) / 2;
        ListNode* l1 = divideConquer(lists, start, mid);
        ListNode* l2 = divideConquer(lists, mid + 1, end);
        return mergeTwo(l1, l2);
    }
    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        if (!l1 || (l2 && l1->val > l2->val)) {
            swap(l1, l2);
        }
        if (l1) {
            l1->next = mergeTwo(l1->next, l2);
        }
        return l1;
        
        */
        // version 2 : heap
        
        if (lists.empty()) {
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode* dummy = new ListNode(0), *cur = dummy;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                q.push(lists[i]);
            }
        }
        while (!q.empty()) {
            ListNode* node = q.top(); q.pop();
            cur->next = node;
            cur = node;
            if (node->next) {
                q.push(node->next);
            }
        }
        
        
        return dummy->next;
        
    }
};