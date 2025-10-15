// https://leetcode.cn/problems/adjacent-increasing-subarrays-detection-ii

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int res = 1;
        int n = nums.size();
        int pre = 0, cur = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                cur += 1;
                res = max(res, max(cur/2, min(pre, cur)));
            }
            else {
                res = max(res, max(cur/2, min(pre, cur)));
                pre = cur;
                cur = 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    cout << sol.maxIncreasingSubarrays(nums) << '\n';
    return true;
}
