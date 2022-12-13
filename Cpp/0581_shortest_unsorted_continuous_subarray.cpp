// https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // If there is a number which is smaller than the current number and
        // is on the right-hand side of the current number, than the current
        // number should be in the subarray.
        // If there is a number which is larger than the current number and
        // is on the left-hand side of the current number, than the current
        // number should be in the subarray.
        int n = nums.size();
        int left = n-1, rightMin = nums[left];
        for (int i = n-1; i >= 0; --i) {
            if (nums[i] > rightMin) {
                left = i;
            }
            else {
                rightMin = nums[i];
            }
        }
        int right = 0, leftMax = nums[right];
        for (int i = 0; i < n; ++i) {
            if (nums[i] < leftMax) {
                right = i;
            }
            else {
                leftMax = nums[i];
            }
        }
        if (left < right) {
            return right - left + 1;
        }
        else {
            return 0;
        }
    }
};
