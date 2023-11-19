// https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = nums[0];
        for (int i: nums) {
            m = max(m, i);
        }
        return (m + m + k - 1) * k / 2;
    }
};
