// https://leetcode.cn/problems/count-partitions-with-even-sum-difference/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int res = 0, left = 0, s = 0;
        for (const int num: nums) s += num;
        for (int i = 0; i < nums.size()-1; ++i) {
            left += nums[i];
            int right = s - left;
            res += 1 - (max(left,right) - min(left,right)) % 2;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,10,3,7,6};
    cout << sol.countPartitions(nums) << '\n';
    return 0;
}