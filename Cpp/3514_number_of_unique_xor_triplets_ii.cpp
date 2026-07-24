// https://leetcode.cn/problems/number-of-unique-xor-triplets-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size(), mx = nums[0];
        for (int num: nums) mx = max(mx, num);
        int u = 1;
        while (u <= mx) u <<= 1;

        vector<bool> ab(u, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                ab[nums[i] ^ nums[j]] = true;
            }
        }

        vector<bool> abc(u, false);
        for (int num = 0; num < u; ++num) {
            if (ab[num]) {
                for (int c: nums) {
                    abc[num ^ c] = true;
                }
            }
        }

        int res = 0;
        for (auto valid: abc) res += valid;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3};
    cout << sol.uniqueXorTriplets(nums) << '\n';
    return 0;
}