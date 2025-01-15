// https://leetcode.cn/problems/sum-of-digit-differences-of-all-pairs/

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int num_len = 0, val = nums[0];
        while (val > 0) {
            num_len += 1;
            val /= 10;
        }
        vector<vector<int>> digits(num_len, vector<int>(10, 0));
        for (auto num: nums) {
            int i = 0;
            val = num;
            while (val > 0) {
                digits[i][val % 10] += 1;
                i += 1;
                val /= 10;
            }
        }
        long long res = 0;
        for (const auto &cnts: digits) {
            for (int i = 0; i < 10; ++i) {
                for (int j = i+1; j < 10; ++j) {
                    res += (long long)cnts[i] * cnts[j];
                }
            }
        }
        return res;
    }
};
