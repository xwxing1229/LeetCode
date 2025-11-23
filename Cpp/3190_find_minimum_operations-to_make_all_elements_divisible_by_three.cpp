// https://leetcode.cn/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res = 0;
        for (int num: nums) {
            int rem = num % 3;
            res += min(rem, 3-rem);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4};
    cout << sol.minimumOperations(nums) << '\n';
    return 0;
}