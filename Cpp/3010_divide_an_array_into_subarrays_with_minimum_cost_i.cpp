// https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res = nums[0];
        int min_1 = min(nums[1], nums[2]), min_2 = max(nums[1], nums[2]);
        for (int i = 3; i < nums.size(); ++i) {
            if (nums[i] <= min_1) {
                min_2 = min_1;
                min_1 = nums[i];
            }
            else if (nums[i] < min_2) {
                min_2 = nums[i];
            }
        }
        res += min_1 + min_2;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 3, 1, 1};
    cout << sol.minimumCost(nums) << '\n';
    return 0;
}