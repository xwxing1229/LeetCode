// https://leetcode.cn/problems/find-closest-number-to-zero/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int res = nums[0], d_min = abs(nums[0]);
        for (int num: nums) {
            int d = abs(num);
            if (d < d_min || (d == d_min && num > res)) {
                res = num;
                d_min = d;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4,-2,1,4,8};
    cout << sol.findClosestNumber(nums) << '\n';
    return 0;
}