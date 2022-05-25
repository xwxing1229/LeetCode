// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        res[0] = searchFirst(nums, target);
        res[1] = searchLast(nums, target);
        return res;
    }

private:
    int searchFirst(vector<int> nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if ((mid == 0) || (nums[mid-1] != target)) {
                    return mid;
                }
                else {
                    r = mid - 1;
                }
            }
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    int searchLast(vector<int> nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if ((mid == nums.size()-1) || (nums[mid+1] != target)) {
                    return mid;
                }
                else {
                    l = mid + 1;
                }
            }
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};