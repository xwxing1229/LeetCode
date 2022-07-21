// https://leetcode.cn/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        // res[i] = nums[0] * ... * nums[i-1]
        for (int i = 1; i < n; ++i) {
            res[i] = res[i-1] * nums[i-1];
        }

        int right = nums[n-1];
        for (int i = n-2; i >= 0; --i) {
            res[i] = res[i] * right;
            right = right * nums[i];
        }
        return res;
    }
};
