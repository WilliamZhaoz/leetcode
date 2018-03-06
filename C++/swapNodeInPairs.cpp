#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class SwapNodeInPairs
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(!head || !head -> next) return head;
        ListNode* next = head -> next;
        head -> next = swapPairs(next -> next);
        next -> next = head;
        return next;    

    }
        

};
int main()
{
    ListNode* test = new ListNode(1);
    test -> next = new ListNode(2);
    test -> next -> next = new ListNode(3);
    test -> next -> next -> next = new ListNode(4);
    test -> next -> next -> next -> next = new ListNode(5);
    SwapNodeInPairs swap;
    ListNode* result = swap.swapPairs(test);
    while(result)
    {
        cout<<result -> val<<endl;
        result = result -> next;
    }
}
