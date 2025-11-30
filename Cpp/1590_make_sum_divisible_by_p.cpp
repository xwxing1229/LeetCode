// https://leetcode.cn/problems/make-sum-divisible-by-p/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int rem = 0;
        for (int num: nums) rem = (rem + num) % p;
        if (rem == 0) return 0;

        // Given sum_i, we want to find sum_j with the maximum j s.t.
        // j <= i and (sum_i - sum_j) % p = sum(nums) % p.
        int n = nums.size(), s = 0;
        int res = n;
        unordered_map<int, int> record;
        record[0] = -1;
        for (int i = 0; i < n; ++i) {
            s = (s + nums[i]) % p;
            record[s] = i;
            int tar = (s - rem + p) % p;
            if (record.find(tar) != record.end()) {
                res = min(res, i - record[tar]);
            }
        }
        return res == n ? -1 : res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {6,3,5,2};
    int p = 9;
    cout << sol.minSubarray(nums, p) << '\n';
    return 0;
}