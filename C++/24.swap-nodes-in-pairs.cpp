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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0), *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) {
            ListNode* tmp = pre->next->next;
            pre->next->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
            pre = tmp->next;
        }
        return dummy->next;
    }
};