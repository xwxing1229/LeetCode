// https://leetcode.cn/problems/find-the-array-concatenation-value/

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;
        int i = 0, j = nums.size()-1;
        while (i < j) {
            int a = nums[i], b = nums[j], num = nums[j];
            while (num > 0) {
                num /= 10;
                a *= 10;
            }
            res += a + b;
            i += 1;
            j -= 1;
        }
        if (i == j) {
            res += nums[i];
        }
        return res;
    }
};
