// https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-i/


class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int pre = nums[0] + nums[1];
        int res = 1;
        for (int i = 2; i < nums.size()-1; i=i+2) {
            if (nums[i] + nums[i+1] == pre) res += 1;
            else break;
        }
        return res;
    }
};