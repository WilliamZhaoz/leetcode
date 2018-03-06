#include <iostream>
#include <string>
#include <stack>
using namespace std;
class ValidParentheses
{
public:
    bool isValid(string s)
    {
        int sL = s.size();
        if(sL % 2 != 0) return false;
        stack<int> myStack;
        for(int i = 0; i < sL; i ++)
        {
            if(myStack.empty()) myStack.push(s[i]);
            else
            {
                if(s[i] == myStack.top() + 1 || s[i] == myStack.top() + 2)
                    myStack.pop();
                else myStack.push(s[i]);
            }
        }
        return myStack.empty();
    }
};
int main()
{
    ValidParentheses myIsValid;
    string test1 = "()()()()";
    string test2 = "{}(){{()}}";
    string test3 = "[)]()";
    cout<<myIsValid.isValid(test1)<<endl;
    cout<<myIsValid.isValid(test2)<<endl;
    cout<<myIsValid.isValid(test3)<<endl;
}
