// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinSub(nums, 0, nums.size()-1);
    }

private:
    int findMinSub(vector<int>& nums, int left, int right) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            int val = nums[mid];

            if (val < nums[right]) {
                right = mid;
            }
            else if (val > nums[right]) {
                left = mid + 1;
            }
            else {
                int tmp1 = findMinSub(nums, left, mid-1);
                int tmp2 = findMinSub(nums, mid+1, right);
                return min(min(tmp1, tmp2), val);
            }
        }
        return nums[left];
    }
};
