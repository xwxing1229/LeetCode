// https://leetcode.cn/problems/count-subarrays-of-length-three-with-a-condition/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i < nums.size()-1; ++i) {
            res += (nums[i-1] + nums[i+1]) * 2 == nums[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,1,4,1};
    cout << sol.countSubarrays(nums) << '\n';
    return 0;
}
