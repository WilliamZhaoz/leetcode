/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // version 1: store the random node in the map.
        // version 2: copy every node after the node, then break the link.
        if (!head) {
            return head;
        }
        RandomListNode *dummy = new RandomListNode(0);
        dummy->next = head;
        while (head) {
            RandomListNode *tmp = new RandomListNode(head->label);
            tmp->next = head->next;
            head->next = tmp;
            head = head->next->next;
        }
        head = dummy->next;
        while (head) {
            if (head->random) {
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
        head = dummy->next;
        dummy->next = head->next;
        RandomListNode *second = head->next;
        while (head) {
            if (!second->next) {
                head->next = NULL;
                break;
            }
            head->next = second->next;
            head = second;
            second = second->next;
        }
        return dummy->next;
        
    }
};