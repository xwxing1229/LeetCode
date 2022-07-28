// https://leetcode.cn/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Time complexity: O(n*log(n)), space complexity: O(1).
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            int cnt = 0;
            for (int num: nums) {
                if (num <= mid) {
                    cnt = cnt + 1;
                }
            }

            if (cnt > mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
