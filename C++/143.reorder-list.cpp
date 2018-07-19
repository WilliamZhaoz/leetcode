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
    void reorderList(ListNode* head) {
        // find the mid
        if (!head || !head->next || !head->next->next) {
            return;
        }
        ListNode *fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse the back half
        ListNode *pre = NULL, *next = slow->next;
        while(next) {
            slow->next = pre;
            pre = slow;
            slow = next;
            next = next->next;
        }
        slow->next = pre;
        /*
        while(slow) {
            cout<<slow->val<<endl;
            slow = slow->next;
        }
        */
        // merge two lists
        pre = head->next;
        while (pre && slow) {
            head->next = slow;
            slow = slow->next;
            head->next->next = pre;
            pre = pre->next;
            head = head->next->next;
        }
        if (pre) {
            pre->next = NULL; // break the circle, or break before the mid node after found the mid node.
        }
        
    }
};