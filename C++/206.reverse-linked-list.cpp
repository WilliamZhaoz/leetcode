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
		// 1.1 and 3 are the best solutions
    // version 1 : 3 pointer iteratively, only reverse one link once move.
    /*
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode *pre = NULL, *cur = head, *nex = head->next;
        while (nex) {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        cur->next = pre;
        return cur;
    }
    */
    /*
    version 1.1 : reverse iteratively directly
    
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        while (head) {
            ListNode *tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
        
    }
    */
    /*
    // version 2 : insert every node after the head since the 2rd node recursively, finally move the head to the end.
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode *pre = head->next, *cur = pre->next;
        while (cur) {
            pre->next = cur->next;
            cur->next = head->next;
            head->next = cur;
            cur = pre->next;
        }
        ListNode * newHead = head->next;
        pre->next = head;
        head->next = NULL;
        return newHead;
    }
    */
    // version 3 : another version 2 implement with a dummy pointer before head.
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *cur = head->next, *dummy_head = new ListNode(0);
        dummy_head->next = head;
        while (cur) {
            head->next = cur->next;
            cur->next = dummy_head->next;
            dummy_head->next = cur;
            cur = head->next;
        }
        return dummy_head->next;
    }
};