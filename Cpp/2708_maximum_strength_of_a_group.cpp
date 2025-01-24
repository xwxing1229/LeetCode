// https://leetcode.cn/problems/maximum-strength-of-a-group/
        
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long min_ = nums[0], max_ = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            long long num = nums[i];
            long long min_pre = min_;
            min_ = min(min(min_, num), min(num*min_, num*max_));
            max_ = max(max(max_, num), max(num*min_pre, num*max_));
        }
        return max_;
    }
};
