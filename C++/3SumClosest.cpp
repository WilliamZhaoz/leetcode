#include <iostream>
#include <vector>
using namespace std;
class ThreeSumClosest
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i ++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum < target) l ++;
                else if(sum > target) r --;
                else return target;
                if(abs(sum - target) < abs(target - sum)) res = sum;
            }
        }
        return res;
    }

};
int main()
{
    ThreeSumClosest myThreeSumClosest;
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> testV(a, a + 5);
    int res = myThreeSumClosest.threeSumClosest(testV, 12);
    cout<<res<<endl;
}
