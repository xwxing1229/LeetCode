// https://leetcode.cn/problems/removing-minimum-and-maximum-from-array/

#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int idx_mn = 0, idx_mx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[idx_mn]) idx_mn = i;
            if (nums[i] > nums[idx_mx]) idx_mx = i;
        }
        int left = min(idx_mn, idx_mx);
        int right = max(idx_mn, idx_mx);
        return min(
            min(right + 1, n - left),
            left + 1 + n - right
        );
    }
};