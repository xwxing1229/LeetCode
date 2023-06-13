// https://leetcode.cn/problems/number-of-unequal-triplets-in-array/

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num1 = nums[i];
            for (int j = i+1; j < nums.size(); ++j) {
                int num2 = nums[j];
                if (num2 == num1) continue;
                for (int k = j+1; k < nums.size(); ++k) {
                    if (nums[k] != num1 && nums[k] != num2) {
                        res += 1;
                    }
                }
            }
        }
        return res;
    }
};