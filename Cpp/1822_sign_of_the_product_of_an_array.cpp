// https://leetcode.cn/problems/sign-of-the-product-of-an-array/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for (int i: nums) {
            if (i < 0) {
                res = -res;
            }
            else if (i == 0) {
                return 0;
            }
        }
        return res;
    }
};
