// https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> remainder(value);
        for (auto &num: nums) {
            remainder[(num % value + value) % value] += 1;
        }
        int res = 0;
        while (remainder[res % value] > 0) {
            remainder[res % value] -= 1;
            res += 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,-10,7,13,6,8};
    int value = 5;
    cout << sol.findSmallestInteger(nums, value) << '\n';
    return 0;
}