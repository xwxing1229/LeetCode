// https://leetcode.cn/problems/trionic-array-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = 0, q = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) p = i;
            else break;
        }
        for (int i = p+1; i < n; ++i) {
            if (nums[i] < nums[i-1]) q = i;
            else break;
        }
        for (int i = q+1; i < n; ++i) {
            if (nums[i] <= nums[i-1]) return false;
        }
        return 0 < p && p < q && q < n-1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,5,4,2,6};
    cout << sol.isTrionic(nums) << '\n';
    return 0;
}