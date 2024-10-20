// https://leetcode.cn/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for (int num: nums) {
            if (num == 0 && res % 2 == 0) {
                res += 1;
            }
            else if (num == 1 && res % 2 == 1) {
                res += 1;
            }
        }
        return res;
    }
};
