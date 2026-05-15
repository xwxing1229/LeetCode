// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            res = nums[mid];
            if (nums[mid] < nums[right]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,4,5,1,2};
    cout << sol.findMin(nums) << '\n';
    return 0;
}