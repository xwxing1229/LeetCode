// https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/
        
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0;
        int i = 0, n = nums.size();
        while (i < n) {
            while (i < n && (nums[i] % 2 != 0 || nums[i] > threshold)) {
                i += 1;
            }
            if (i >= n) {
                break;
            }
            int left = i;
            i += 1;
            while (i < n && nums[i] % 2 != nums[i-1] % 2 && nums[i] <= threshold) {
                i += 1;
            }
            res = max(res, i-left);
        }
        return res;
    }
};