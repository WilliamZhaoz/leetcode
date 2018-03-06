#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class RemoveNthNodeFromEndofList
{
public:
    ListNode* removeNode(ListNode* head, int n)
    {
        ListNode* res = new ListNode(0);
        ListNode* tempPL = new ListNode(0);
        ListNode* tempPR = new ListNode(0);
        res -> next = head;
        tempPL -> next = head;
        tempPR -> next = head;
        for(int c = 0; c < n; c ++) tempPR = tempPR -> next; 
        if(!tempPR -> next) return res -> next -> next;
        while(tempPR -> next)
        {
            tempPL = tempPL -> next;
            tempPR = tempPR -> next;
        }
        tempPL -> next = tempPL -> next -> next;
        return res -> next;
    }
    
};
int main()
{
    RemoveNthNodeFromEndofList myRemove;
    ListNode* test = new ListNode(0);
    test -> next = new ListNode(1);
    test -> next -> next = new ListNode(2);
    ListNode* res = myRemove.removeNode(test, 1);
    while(res)
    {
        cout<<res -> val<<endl;
        res = res -> next;
    }
}
