// https://leetcode.cn/problems/rotate-function/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, s = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            f += i * nums[i];
            s += nums[i];
        }
        int res = f;
        for (int i = 1; i < n; ++i) {
            f += s - n * nums[n - i];
            res = max(res, f);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 6};
    cout << sol.maxRotateFunction(nums) << '\n';
    return 0;
}