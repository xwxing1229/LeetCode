// https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-i/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        
        int n = nums.size(), cnt = 1;
        for (int i = 1; i < k-1; ++i) {
            if (nums[i] - nums[i-1] == 1) {
                cnt += 1;
            }
            else {
                cnt = 1;
            }
        }
        vector<int> res(n-k+1, -1);
        for (int i = k-1; i < n; ++i) {
            if (nums[i] - nums[i-1] == 1) {
                cnt += 1;
            }
            else {
                cnt = 1;
            }

            if (cnt >= k) {
                res[i-(k-1)] = nums[i];
            }
        }
        return res;
    }
};
