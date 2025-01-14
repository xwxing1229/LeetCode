// https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-i/

#include <iostream>
#include <vector>

using namespace std;
    
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        for (int num: nums) {
            if (num < k) res += 1;
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2,11,10,1,3};
    int k = 10;
    cout << sol.minOperations(nums, k) << '\n';
    return 0;
}