// https://leetcode.cn/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int tmp_max = nums[0], tmp_min = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmp = max(tmp_max*nums[i], max(tmp_min*nums[i], nums[i]));
            tmp_min = min(tmp_max*nums[i], min(tmp_min*nums[i], nums[i]));
            tmp_max = tmp;
            res = max(res, tmp_max);
        }
        return res;
    }
};
