// https://leetcode.cn/problems/find-the-value-of-the-partition/
        
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = nums[1] - nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            res = min(res, nums[i]-nums[i-1]);
        }
        return res;
    }
};
