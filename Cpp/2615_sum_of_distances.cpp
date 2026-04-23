// https://leetcode.cn/problems/sum-of-distances/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<long long>> cumsum;
        unordered_map<int, long long> helper;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            helper[num] += i;
            cumsum[num].push_back(helper[num]);
        }

        vector<long long> res(nums.size(), 0);
        for (const auto &[num, cs]: cumsum) {
            int n = cs.size();
            long long idx = cs[0];
            res[idx] = cs.back() - idx * n;
            for (int i = 1; i < n; ++i) {
                idx = cs[i] - cs[i-1];
                long long left = idx * i - cs[i-1];
                long long right = cs.back() - cs[i] - idx * (n-1-i);
                res[idx] = left + right;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,1,1,2}; // 5,0,3,4,0
    auto res = sol.distance(nums);
    for (const auto &val: res) cout << val << ", ";
    cout << '\n';
    return 0;
}