// https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Increasing n-1 elements by 1 works similarly as decreasing 1 element by 1.
        int min_ = nums[0], sum_ = 0;
        for (int num: nums) {
            if (num < min_) min_ = num;
            sum_ += num;
        }
        int res = sum_ - min_ * nums.size();
        return res;
    }
};
