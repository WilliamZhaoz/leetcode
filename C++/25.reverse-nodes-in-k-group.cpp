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
    // version 1 : my version 
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* dummy = new ListNode(0), *pre = dummy, *end = dummy;
        dummy->next = head;
        while (1) {
            for (int i = 0; i < k; i++) {
                end = end->next;
                if (!end) {
                    return dummy->next;
                }
            }
            ListNode* start = pre->next, *endn = end->next;
            pre->next = reverse(start, end, endn);
            pre = start;
            pre->next = endn;
            end = pre;
        }
        return dummy->next;
        
    }
    ListNode* reverse(ListNode* start, ListNode* end, ListNode* endn) {
        if (start == end) {
            return start;
        }
        ListNode* pre = NULL, *cur = start, *nex = cur->next; 
        while (cur != endn) {
            cur->next = pre;
            pre = cur;
            cur = nex;
            if (nex != endn) {
                nex = nex->next;
            }
        }
        return pre;
    }
};