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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // version 1: figure out the length of A and B, the longer one move difference length first
        /*
        int la = 0, lb = 0;
        ListNode *cA = headA, *cB = headB;
        while (cA) {
            cA = cA->next;
            la++;
        }
        while (cB) {
            cB = cB->next;
            lb++;
        }
        cout<<la<<lb;
        if (la < lb) {
            swap(headA, headB);
        }
        for (int i = 0; i < abs(la - lb); i++) {
            headA = headA->next;
        }
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
        */
        // version 2: one node traverse from A start to A end then to B start, another node also do it, the node they meet is the result.
        if (!headA || !headB) {
            return NULL;
        }
        ListNode *tA = headA, *tB = headB;
        while (tA != tB) {
            tA = tA ? tA->next: headB;
            tB = tB ? tB->next: headA;
        }
        return tA;
        
    }
};