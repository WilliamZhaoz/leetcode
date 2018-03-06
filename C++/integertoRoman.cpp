#include <iostream>
#include <string>
using namespace std;
class IntegertoRoman
{
public:
    string integertoRoman(int num)
    {
        string res = "";
        string map[4][10]={
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM", "", "", "", "", "", ""}
        };
        res += map[3][num / 1000];
        res += map[2][num / 100 % 10];
        res += map[1][num / 10 % 10];
        res += map[0][num % 10];
        return res;
    }
};

int main()
{
    IntegertoRoman myInttoRoman;
    cout<<myInttoRoman.integertoRoman(1234)<<endl;
    return 0;
}
