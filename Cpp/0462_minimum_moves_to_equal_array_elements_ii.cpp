// https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // After sorting, let all numbers equal nums[k].
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = (n - 1) / 2;
        int res = 0;
        for (int i = 0; i < k; ++i) res += nums[k] - nums[i];
        for (int i = k+1; i < n; ++i) res += nums[i] - nums[k];
        return res;
    }
};