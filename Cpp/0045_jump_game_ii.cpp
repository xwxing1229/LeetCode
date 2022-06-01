// https://leetcode.cn/problems/jump-game-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int max_reach = 0, end = 0;
        int res = 0;
        for (int i = 0; i < nums.size()-1; ++i) {
            max_reach = max(max_reach, i+nums[i]);
            if (i == end) {
                end = max_reach;
                res = res + 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> nums = {2,3,1,1,4};

    cout << solu.jump(nums) << endl;
    
    return 0;
}