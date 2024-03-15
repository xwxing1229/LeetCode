// https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations/
        
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long res = nums.back();
        for (int i = nums.size()-2; i >= 0; --i) {
            if (nums[i] <= res) res += nums[i];
            else res = nums[i];
        }
        return res;
    }
};