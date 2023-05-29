// https://leetcode.cn/problems/average-value-of-even-numbers-that-are-divisible-by-three/

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int s = 0, n = 0;
        for (int num: nums) {
            if (num % 6 == 0) {
                s += num;
                n += 1;
            }
        }
        return n > 0 ? s/n : 0;
    }
};
