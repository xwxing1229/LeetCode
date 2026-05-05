// https://leetcode.cn/problems/longest-balanced-subarray-i/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> cnt { {nums[i], 1} };
            vector<int> record(2, 0);
            record[nums[i] % 2] += 1;
            for (int j = i+1; j < n; ++j) {
                cnt[nums[j]] += 1;
                if (cnt[nums[j]] == 1) {
                    record[nums[j] % 2] += 1;
                }
                if (record[0] == record[1]) {
                    res = max(res, j-i+1);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,2};
    cout << sol.longestBalanced(nums) << '\n';
    return 0;
}