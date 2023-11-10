// https://leetcode.cn/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xor_all = 0;
        for (int num: nums) {
            xor_all ^= num;
        }
        int low_bit = xor_all & (-xor_all);
        vector<int> res(2, 0);
        for (int num: nums) {
            res[(num & low_bit) != 0] ^= num;
        }
        return res;
    }
};
