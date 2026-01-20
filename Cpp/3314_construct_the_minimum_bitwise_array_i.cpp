// https://leetcode.cn/problems/construct-the-minimum-bitwise-array-i/

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
            for (int val = 1; val < num; ++val) {
                if ((val | (val+1)) == num) {
                    res[i] = val;
                    break;
                }
            }
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