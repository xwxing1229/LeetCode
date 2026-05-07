// https://leetcode.cn/problems/jump-game-ix/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> premax(nums);
        for (int i = 1; i < n; ++i) {
            premax[i] = max(premax[i-1], nums[i]);
        }
        int sufmin = nums.back(), sufmin_idx = n - 1;

        vector<int> res(premax);
        for (int i = n-2; i >= 0; --i) {
            res[i] = premax[i] <= sufmin ? premax[i] : res[sufmin_idx];
            if (nums[i] < sufmin) {
                sufmin = nums[i];
                sufmin_idx = i;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {11, 18, 11};
    auto res = sol.maxValue(nums);
    for (const auto &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}