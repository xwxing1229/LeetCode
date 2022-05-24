// https://leetcode.cn/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), idx = n - 1;
        while (idx > 0) {
            if (nums[idx-1] < nums[idx]) {
                int tmp = nums[idx-1];
                // Find the smallest values that is greater than nums[idx-1]
                // and that is on the right of nums[idx-1].
                for (int i = n - 1; i >= idx; --i) {
                    if (tmp < nums[i]) {
                        nums[idx-1] = nums[i];
                        nums[i] = tmp;
                        break;
                    }
                }
                break;
            }

            idx = idx - 1;
        }

        // Reverse.
        for (int i = 0; i < (n-idx)/2; ++i) {
            int tmp = nums[idx+i];
            nums[idx+i] = nums[n-1-i];
            nums[n-1-i] = tmp;
        }

    }
};