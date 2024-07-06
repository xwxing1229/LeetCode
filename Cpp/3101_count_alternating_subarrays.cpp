// https://leetcode.cn/problems/count-alternating-subarrays/
        
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        nums.push_back(nums.back());
        long long res = 0;
        int start = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1]) continue;
            long long n = i - start;
            res += (n + 1) * n / 2;
            start = i;
        }
        return res;
    }
};
