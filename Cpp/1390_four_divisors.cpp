// https://leetcode.cn/problems/four-divisors/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (const auto &num: nums) {
            int factor1 = 0, factor2 = 0;
            for (int i = 2; i <= sqrt(num); ++i) {
                int j = num / i;
                if (i * j != num) {
                    continue;
                }
                else if (i == j || factor1 > 0) {
                    factor1 = 0;
                    break;
                }
                else {
                    factor1 = i;
                    factor2 = j;
                }
            }
            if (factor1 > 0) {
                res += 1 + num + factor1 + factor2;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {21, 4, 7};
    cout << sol.sumFourDivisors(nums) << '\n';
    return 0;
}