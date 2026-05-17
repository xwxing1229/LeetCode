// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else if (nums[mid] < nums[right]) right = mid;
            else right -= 1;
        }
        return nums[left];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,3,3,1};
    cout << sol.findMin(nums) << '\n';
    return 0;
}