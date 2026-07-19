// https://leetcode.cn/problems/find-greatest-common-divisor-of-array/

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        return gcd(mn, mx);
    }
};