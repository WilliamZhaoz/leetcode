#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
}
class MergeTwoSortedLists
{
public:
    mergeTwoSortedLists(ListNode* l1, ListNode* l2)
    {
        ListNode* res = new ListNode(0);
        ListNode* tmp = res;
        while(l1 && l2)
        {
            if(l1 -> val > l2 -> val)
            {
                tmp -> next = l2;
                l2 = l2 -> next;
            }
            else
            {
                tmp -> next = l1;
                l1 = l1 -> next; 
            }
            tmp = tmp -> next;
        }
        tmp -> next = l1 ? l1 : l2;
        return res -> next;
    }
};
int main()
{
    
}
