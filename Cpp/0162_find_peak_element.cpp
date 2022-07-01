// https://leetcode.cn/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val_left = nums[max(0, mid-1)];
            int val_mid = nums[mid];
            int val_right = nums[min(n-1, mid+1)];
            if ((val_left <= val_mid) && (val_mid >= val_right)) {
                return mid;
            }

            if (val_mid <= val_right) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
