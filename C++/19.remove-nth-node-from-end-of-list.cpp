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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast = dummy, *slow = dummy;
        for (int i = 0; i < n; i++) {
            slow = slow->next;
        }
        while (slow->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = fast->next->next;
        return dummy->next;
        
    }
};