#include <iostream>
#include <vector>
using namespace std;
class FourSum
{
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target)
    {
        vector<vector<int> > res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i ++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if(nums[i] + nums[n -1] + nums[n - 2] + nums[n - 3] < target) continue;
            for(int j = i + 1; j < n - 2; j ++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if(nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                int l = j + 1, r = n - 1;
                while(l < r)
                {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum < target) l ++;
                    else if(sum > target) r --;
                    else
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        do l ++; while(l < r && nums[l] == nums[l - 1]);
                        do r --; while(l < r && nums[r] == nums[r + 1]);
                    }
                }
            }
        }
        return res;
    }
        
};
int main()
{
    FourSum myFourSum;
    int tmp[12] = {5, 2, 3, 4, 5, 3, 6, 1, 7, 8, 9, 10};
    vector<int> test(tmp, tmp + 12);
    vector<vector<int> > res = myFourSum.fourSum(test, 20);
    for(auto vv : res)
    {
        for(auto v : vv)
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;

}
