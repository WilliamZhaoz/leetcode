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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return NULL;
        }
        ListNode *fast = head->next->next, *slow = head->next;
        while(fast && fast->next) {
            if (fast == slow) {
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
            
        }
        if (fast != slow) {
            return NULL;
            
        }
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};