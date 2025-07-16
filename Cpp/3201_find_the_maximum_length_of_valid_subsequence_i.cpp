// https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        auto f = [&](int rem) {
            int res = 0;
            for (const auto num: nums) {
                res += (num % 2 == rem);
            }
            return res;
        };

        int res = 1, pre = nums[0] % 2;
        for (const auto num: nums) {
            int cur = num % 2;
            if (cur != pre) {
                res += 1;
                pre = cur;
            }
        }
        res = max(res, f(0));
        res = max(res, f(1));
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4};
    cout << sol.maximumLength(nums) << '\n';
    return 0;
}
