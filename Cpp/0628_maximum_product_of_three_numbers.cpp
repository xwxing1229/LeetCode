// https://leetcode.cn/problems/maximum-product-of-three-numbers/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(
            nums[n-1] * nums[n-2] * nums[n-3],
            nums[n-1] * nums[0] * nums[1]
        );
    }
};