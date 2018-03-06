#include <iostream>
#include <vector>
#include <string>
using namespace std;
class GenerateParentheses
{
public:
    vector<string> generateParentheses(int n)
    {
        vector<string> res;
        addPar(res, "", n, 0);
        return res;
    }
    void addPar(vector<string> &v, string str, int l, int r)
    {
        if(l == 0 && r == 0)
        {
            v.push_back(str);
            return;
        }
        if(r > 0) addPar(v, str + ")", l, r - 1);
        if(l > 0) addPar(v, str + "(", l - 1, r + 1);
    }

        
};
int main()
{
    GenerateParentheses generate;
    vector<string> result = generate.generateParentheses(3);
    for(auto str : result)
        cout<<str<<endl;
    return 0;
}
