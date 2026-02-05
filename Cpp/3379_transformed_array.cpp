// https://leetcode.cn/problems/transformed-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int idx = (i + nums[i] % n + n) % n;
            res[i] = nums[idx];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,-2,1,1};
    auto res = sol.constructTransformedArray(nums);
    for (const auto &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}