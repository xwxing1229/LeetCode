// https://leetcode.cn/problems/longest-alternating-subarray/
        
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int res = 0;
        int i = 0, n = nums.size(), diff = 1;
        while (i < n) {
            int start = i;
            while (i+1 < n && nums[i+1] - nums[i] == diff) {
                i += 1;
                diff *= (-1);
            }
            res = max(res, i-start+1);
            diff = 1;
            if ((i+1 < n && nums[i+1] - nums[i] != diff) || (i == n-1)) {
                i += 1;
            }
        }
        return res > 1 ? res : -1;
    }
};
