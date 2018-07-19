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
    /*
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy;
        while(l1 || l2) {
            ListNode *m;
            if ((l1 && !l2) || (l1 && l2 && l1->val < l2->val)) {
                m = l1;
                l1 = l1->next;
            } else {
                m = l2;
                l2 = l2->next;
            }
            tmp->next = m;
            tmp = tmp->next;
        }
        return dummy->next;
    }
    */
    // a recurrent version:
    /*
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
    */
    // a recurrent and amazing version:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || (l2 && l1->val > l2->val)) swap(l1, l2);
        if (l1) l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};