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
    ListNode* rotateRight(ListNode* head, int k) {
        // version 1: 
        /*
        if (!head || k == 0) {
            return head;
        }
        int l = 0;
        ListNode *node = head;
        while (node) {
            node = node->next;
            l++;
        }
        l = k % l;
        if (l == 0) {
            return head;
        }
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < l; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *newhead = slow->next;
        slow->next = NULL;
        fast->next = head;
        return newhead;
        */
        //version 2: 
        if (!head || k == 0) {
            return head;
        }
        int n = 1;
        ListNode *node = head;
        while (node->next) {
            node = node->next;
            n++;
        }
        int l = k % n;
        if (l == 0) {
            return head;
        }
        node->next = head;
        while (n - l) {
            node = node->next;
            l++;
        }
        ListNode *newhead = node->next;
        node->next = NULL;
        return newhead;
        
    }
};