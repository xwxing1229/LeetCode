// https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = nums[mid];
            if (target == val) {
                return true;
            }

            if (nums[left] < val) {
                if ((nums[left] <= target) && (target < val)) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else if (val < nums[right]) {
                if ((val < target) && (target <= nums[right])) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            else {
                if (nums[left] == target) {
                    return true;
                }
                left = left + 1;
            }
        }
        return false;
    }
};
