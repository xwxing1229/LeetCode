// https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/

#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = max(nums[0], nums[1]);
        int mx2 = nums[0] + nums[1] - mx1;
        for (int i = 2; i < nums.size(); ++i) {
            int num = nums[i];
            if (num >= mx1) {
                mx2 = mx1;
                mx1 = num;
            }
            else if (num > mx2) {
                mx2 = num;
            }
        }
        return (mx1 - 1) * (mx2 - 1);
    }
};