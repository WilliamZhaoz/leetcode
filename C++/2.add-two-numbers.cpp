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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1head = l1, *l2head = l2, *res = l1head, *pre = l2;
        int carry = 0;
        while (l1 || l2) {
            int sum = (l1 ? l1->val : 0) + carry + (l2 ? l2->val : 0);
            carry = sum / 10;
            sum = sum % 10;
            if (l1) {
                l1->val = sum;
                pre = l1;
                l1 = l1->next;
                res = l1head;                
            }
            if (l2) {
                l2->val = sum;
                pre = l2;
                l2 = l2->next;
                res = l2head;                
            }
        }
        if (carry) {
            pre->next = new ListNode(carry);
        }
        return res;
    }
};