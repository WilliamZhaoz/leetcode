#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LetterCombinationsofaPhoneNumber
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if(digits.empty()) return res;
        vector<string> map = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for(int i = 0; i < digits.size(); i ++)
        {
            vector<string> tmp;
            for(auto c : map[digits[i] - '0'])
            {
                for(auto r : res)
                {
                    tmp.push_back(r + c);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};

class LetterCombinationsRecursion
{
public:
    vector<string> res;
    vector<string> map = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void recursion(string s, string cur)
    {
        if(!s.size())
        {
            res.push_back(cur);
            return;
        }
        for(auto c : map[s[0] - '0'])
        {
            recursion(s.substr(1, s.size() - 1), cur + c);
        }
    }
    vector<string> letterComRecursion(string digits)
    {
        if(!digits.size()) return res;
        recursion(digits, "");
        return res;
    }
};

int main()
{
    LetterCombinationsofaPhoneNumber myLetter;
    LetterCombinationsRecursion myLetterR;
    string test = "234";
    //vector<string> res = myLetter.letterCombinations(test);
    vector<string> res = myLetterR.letterComRecursion(test);

    for(auto r : res)
    {
        cout<<r<<endl;
    }
    return 0;
}
