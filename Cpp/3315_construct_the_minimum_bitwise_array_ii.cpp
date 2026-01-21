// https://leetcode.cn/problems/construct-the-minimum-bitwise-array-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            const int &num = nums[i];
            if (num % 2 == 0) continue;
            int k = 0;
            while ((num >> k) & 1) {
                k += 1;
            }
            res[i] = num ^ (1 << (k-1));
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,5,7};
    auto res = sol.minBitwiseArray(nums);
    for (const auto &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}