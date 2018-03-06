#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LongestCommonPrefix
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string res = strs[0];
        while(res.size() > 0)
        {
            for(int i = 0; i < strs.size(); i ++)
            {
                if(0 != strs[i].find(res)) 
                {
                    res = res.substr(0, res.size() - 1);
                    break;
                }
                if(i == strs.size() - 1) return res;
            }
        }
        return "";
    }
};
int main()
{
    LongestCommonPrefix myPrefix;
    string test[5] = {"abcsdfsdf", "abcddf", "abcdfdsfdsf", "ab", "abcds"};
    vector<string> testV(test, test + 5);
    cout<<myPrefix.longestCommonPrefix(testV)<<endl;
    return 0;
}
