// https://leetcode.cn/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            while ((num >= 1) && (num <= n)) {
                int tmp = nums[num-1];
                if (tmp == num) {
                    break;
                }

                nums[num-1] = num;
                nums[i] = tmp;
                num = tmp;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};
