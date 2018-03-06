#include <iostream>
#include <vector>
using namespace std;
class ThreeSum
{
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int numsL = nums.size();
        for(int i = 0; i < numsL - 2; i ++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if(nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if(nums[i] + nums[numsL - 1] + nums[numsL - 2] < 0) continue;
            int l = i + 1, r = numsL -1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) r --;
                else if(sum < 0) l ++;
                else
                {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    do l ++; while(l < r && nums[l] == nums[l - 1]);
                    do r --; while(l < r && nums[r] == nums[r + 1]);
                }
            }
        }
        return res;
    }
};
int main()
{
    ThreeSum myThreeSum;
    int a[6] = {-1, 0, 1, 2, -1, -4};
    vector<int> test(a, a + 6);
    vector<vector<int> > res = myThreeSum.threeSum(test);
    for(auto v : res)
    {
        for(auto i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
