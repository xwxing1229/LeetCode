// https://leetcode.cn/problems/visit-array-positions-to-maximize-score/
        
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long odd = nums[0], even = -1000000;
        if (nums[0] % 2 == 0) {
            odd = -1000000;
            even = nums[0];
        }
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (num % 2 == 0) {
                even = max(even + num, odd + num - x);
            }
            else {
                odd = max(odd + num, even + num - x);
            }
        }
        return max(odd, even);
    }
};
