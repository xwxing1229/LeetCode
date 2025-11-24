// https://leetcode.cn/problems/binary-prefix-divisible-by-5/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> res(n, false);
        int num = 0;
        for (int i = 0; i < n; ++i) {
            num = (num << 1 | nums[i]) % 5;
            res[i] = (num == 0);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,1,1,1,1,1}; // 1,0,0,0,1,0
    auto res = sol.prefixesDivBy5(nums);
    for (int val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}