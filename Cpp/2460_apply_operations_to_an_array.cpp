// https://leetcode.cn/problems/apply-operations-to-an-array/

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; ++i) {
            if (nums[i] == nums[i+1]) {
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
        }
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && nums[j] != 0) {
                j += 1;
            }
            if (nums[i] != 0 && i > j) {
                nums[j] = nums[i];
                nums[i] = 0;
                j += 1;
            }
        }
        return nums;
    }
};