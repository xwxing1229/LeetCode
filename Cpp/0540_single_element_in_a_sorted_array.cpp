// https://leetcode.cn/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int res = nums.back();
        int left = 0, right = n/2-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[2*mid] == nums[2*mid+1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
                res = nums[2*mid];
            }
        }
        return res;
    }
};
