// https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int s_element = 0, s_digit = 0;
        for (int num: nums) {
            s_element += num;
            int val = num;
            while (val > 0) {
                s_digit += val % 10;
                val /= 10;
            }
        }
        return abs(s_element - s_digit);
    }
};
