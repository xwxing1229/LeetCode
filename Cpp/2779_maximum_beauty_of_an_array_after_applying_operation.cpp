// https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/
        
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, diff = k * 2;
        int res = 1;
        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > diff) {
                left += 1;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};
