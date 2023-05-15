// https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> check(1001, 0);
        for (int i: nums) {
            if (i < 0) {
                check[-i] = 1;
            }
        }
        int res = -1;
        for (int i: nums) {
            if (i > 0 && check[i] == 1 && i > res) {
                res = i;
            }
        }
        return res;
    }
};