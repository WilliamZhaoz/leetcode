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
    // version 1: reverse + No2 Add Two Numbers
    /*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *l1head = l1, *l2head = l2, *res = l2head, *pre = l2;
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
        return reverse(res);
    }
    ListNode* reverse(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *pre = NULL, *cur = head, *nex = head->next;
        while (cur) {
            cur->next = pre;
            pre = cur;
            cur = nex;
            if (nex) {
                nex = nex->next;
            }
        }
        return pre;
        
    }
    */
    // version 2: use stack or recurseive version
    /*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1l = getLength(l1), l2l = getLength(l2);
        if (l1l < l2l) {
            swap(l1, l2);
        }
        ListNode* dummy = new ListNode(1);
        dummy->next = helper(l1, l2, abs(l1l - l2l));
        if(dummy->next->val > 9) {
            dummy->next->val %= 10;
            return dummy;
        }
        return dummy->next;
    }  
    ListNode* helper(ListNode* l1, ListNode* l2, int diff) {
        if (!l1) {
            return NULL;
        }
        ListNode *res = new ListNode(diff == 0 ? l1->val + l2->val : l1->val);
        ListNode *post = (diff == 0) ? helper(l1->next, l2->next, 0) : helper(l1->next, l2, diff - 1);
        if (post && post->val > 9) {
            post->val %= 10;
            ++res->val;
        }
        res->next = post;
        return res;
    }
    int getLength(ListNode* head) {
        int res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }
    */
    // version 3: use a extra pointer, pointting to the first number less than 9 from right. if the carry is more than 9, the pointer value add 1, and all the values after it set 0. 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1l = getLength(l1), l2l = getLength(l2), diff = abs(l1l - l2l);
        if (l1l < l2l) {
            swap(l1, l2);
        }
        ListNode *dummy = new ListNode(0), *cur = dummy, *carrypos = cur;
        while (diff > 0) {
            cur->next = new ListNode(l1->val);
            if (l1->val != 9) {
                carrypos = cur->next;
            }
            cur = cur->next;
            l1 = l1->next;
            diff--;
        }
        while (l1) {
            int val = l1->val + l2->val;
            if (val > 9) {
                val %= 10;
                ++carrypos->val;
                while (carrypos->next) {
                    carrypos->next->val = 0;
                    carrypos = carrypos->next;
                }
                carrypos = cur;
            }
            cur->next = new ListNode(val);
            if (val != 9) {
                carrypos = cur->next;
            }
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        return (dummy->val == 1) ? dummy : dummy->next;
    }
    int getLength(ListNode* head) {
        int res = 0;
        while (head) {
            res++;
            head = head->next;
        }
        return res;
    }
};