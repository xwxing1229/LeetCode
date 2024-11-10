// https://leetcode.cn/problems/find-the-power-of-k-size-subarrays-ii/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;

        int n = nums.size(), cnt = 1;
        for (int i = n-2; i > n-k; --i) {
            if (nums[i] + 1 == nums[i+1]) {
                cnt += 1;
            }
            else {
                cnt = 1;
            }
        }

        vector<int> res(n-k+1, -1);
        for (int i = n-k; i > -1; --i) {
            if (nums[i] + 1 == nums[i+1]) {
                cnt += 1;
            }
            else {
                cnt = 1;
            }

            if (cnt >= k) {
                res[i] = nums[i+k-1];
            }
        }
        return res;
    }
};
