// https://leetcode.cn/problems/smallest-index-with-digit-sum-equal-to-index/

#include <vector>

using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i], s = 0;
            while (num > 0) {
                s += num % 10;
                num /= 10;
            }
            if (i == s) return i;
        }
        return -1;
    }
};