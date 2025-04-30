// https://leetcode.cn/problems/find-numbers-with-even-number-of-digits/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        auto digits = [](int num) {
            int res = 0;
            while (num) {
                res += 1;
                num /= 10;
            }
            return res;
        };
        int res = nums.size();
        for (const auto &num: nums) {
            res -= digits(num) % 2;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {12,345,2,6,7896};
    cout << sol.findNumbers(nums) << '\n';
    return 0;
}