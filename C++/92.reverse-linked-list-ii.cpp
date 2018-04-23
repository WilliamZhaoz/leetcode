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
    // version 1 : dummy node + insert function
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m >= n) return head;
        ListNode *dummy_head = new ListNode(0), *cur = dummy_head;
        dummy_head->next = head;
        for (int i = 1; i < m; i++) {
            cur = cur->next;
            if (!cur->next) {
                return head;
            }
        }
        head = cur->next;
        for (; m < n ;m++) {
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = cur->next;
            cur->next = tmp;
        }
        return dummy_head->next;
    }
    // version 2 : reverse directly 
};