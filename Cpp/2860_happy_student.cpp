// https://leetcode.cn/problems/happy-students/
        
class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 1;
        if (nums[0] > 0) {
            res += 1;
        }
        for (int i = 1; i < nums.size(); ++i) {
            if (i > nums[i-1] && i < nums[i]) {
                res += 1;
            }
        }
        return res;
    }
};