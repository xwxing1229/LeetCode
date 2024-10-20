// https://leetcode.cn/problems/minimum-average-of-smallest-and-largest-elements/

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        double res = (nums[left] + nums[right]) / 2.0;
        while (left < right) {
            res = min(res, (nums[left] + nums[right]) / 2.0);
            left += 1;
            right -= 1;
        }
        return res;
    }
};
