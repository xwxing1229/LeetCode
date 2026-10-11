// https://leetcode.cn/problems/sum-of-squares-of-special-elements/

#include <vector>

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (n % (i+1) == 0) {
                res += nums[i] * nums[i];
            }
        }
        return res;
    }
};