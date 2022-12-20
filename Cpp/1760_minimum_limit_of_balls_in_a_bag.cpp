// https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int res = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int requiredOps = 0;
            for (int num: nums) {
                requiredOps += (num - 1) / mid;
            }
            if (requiredOps <= maxOperations) {
                right = mid - 1;
                res = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};
