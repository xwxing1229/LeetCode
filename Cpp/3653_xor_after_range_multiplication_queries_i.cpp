// https://leetcode.cn/problems/xor-after-range-multiplication-queries-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        for (const auto &q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            int idx = l;
            while (idx <= r) {
                nums[idx] = ((long)nums[idx] * v) % mod;
                idx += k;
            }
        }
        int res = 0;
        for (const int &num: nums) res ^= num;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1};
    vector<vector<int>> queries = {{0,2,1,4}};
    cout << sol.xorAfterQueries(nums, queries) << '\n';
    return 0;
}