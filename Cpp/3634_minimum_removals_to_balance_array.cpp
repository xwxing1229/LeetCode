// https://leetcode.cn/problems/minimum-removals-to-balance-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int max_len = 0;
        int n = nums.size(), right = 0;
        for (int left = 0; left < n; ++left) {
            while (right < n && (double)nums[right] / nums[left] <= k) {
                right += 1;
            }
            max_len = max(max_len, right-left);
        }
        return n - max_len;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1, 5};
    int k = 2;
    cout << sol.minRemoval(nums, k) << '\n';
    return 0;
}