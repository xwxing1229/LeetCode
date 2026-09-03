// https://leetcode.cn/problems/construct-uniform-parity-array-ii/

#include <vector>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd_min = -1;
        for (const int num: nums1) {
            if (num % 2 == 1 && (odd_min < 0 || odd_min > num)) {
                odd_min = num;
            }
        }
        if (odd_min < 0) return true;
        for (const int num: nums1) {
            if (num % 2 == 0 && num - odd_min < 1) {
                return false;
            }
        }
        return true;
    }
};