// https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0;
        // The index of the start element of the subarray,
        // and the index of the neatest element which is >= left.
        int start = 0, nearest = 0;
        int cur_max = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num > cur_max) cur_max = num;
            if (num >= left) nearest = i;

            if ((cur_max >= left) && (cur_max <= right)) {
                res += nearest - start + 1;
            }
            else if (cur_max > right) {
                start = i + 1;
                if (start < nums.size()) cur_max = nums[start];
            }
        }
        return res;
    }
};
