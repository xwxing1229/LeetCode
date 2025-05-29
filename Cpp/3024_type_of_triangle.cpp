// https://leetcode.cn/problems/type-of-triangle/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
    
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) return "none";
        else if (nums[0] == nums[2]) return "equilateral";
        else if (nums[0] == nums[1] || nums[2] == nums[1]) return "isosceles";
        else return "scalene";
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,4,5};
    cout << sol.triangleType(nums) << '\n';
    return 0;
}