// https://leetcode.cn/problems/minimum-element-after-replacement-with-digit-sum/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        auto DigitSum = [](int num) {
            int res = 0;
            while (num > 0) {
                res += num % 10;
                num /= 10;
            }
            return res;
        };

        int res = DigitSum(nums[0]);
        for (const int &num: nums) {
            res = min(res, DigitSum(num));
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 11, 12, 13};
    cout << sol.minElement(nums) << '\n';
    return 0;
}