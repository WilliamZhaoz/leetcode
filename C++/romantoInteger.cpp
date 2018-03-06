#include <iostream>
#include <string>
using namespace std;
class RomantoInteger
{
public:
    int romantoInteger(string s)
    {
        int res = 0;
        for(int i = 0; i < s.size(); i ++)
        {
            switch(s[i])
            {
                case 'M' : res += 1000; break;
                case 'D' : res += 500; break;
                case 'C' : 
                    if(i + 1 < s.size())
                    {
                        if(s[i + 1] == 'D' || s[i + 1] == 'M')
                            res -= 100;
                        else res += 100;
                    }
                    else res += 100;
                    break;
                case 'L' : res += 50; break;
                case 'X' :
                    if(i + 1 < s.size())
                    {
                        if(s[i + 1] == 'L' || s[i + 1] == 'C')
                            res -= 10;
                        else res += 10;
                    }
                    else res += 10;
                    break;
                case 'V' : res += 5; break;
                case 'I' :
                    if(i + 1 < s.size())
                    {
                        if(s[i + 1] == 'X' || s[i + 1] == 'V')
                            res -= 1;
                        else res += 1;
                    }
                    else res += 1;break;
            }
        }
        return res;
    }    
};
int main()
{
    RomantoInteger myRomantoInt;
    cout<<myRomantoInt.romantoInteger("MXXI")<<endl;
    return 0;
}
