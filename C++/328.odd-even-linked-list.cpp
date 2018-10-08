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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        } 
        ListNode* head1 = head, *head2 = head->next, *dummy1 = head1, *dummy2 = head2;
        while (head2 && head2->next) {
            head1->next = head1->next->next;
            head1 = head1->next;
            head2->next = head2->next->next;
            head2 = head2->next;
        }
        head1->next = dummy2;
        return dummy1;
    }
};
