// https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long res = 0;
        int cumxor = 0;
        unordered_map<int, int> cnts;
        cnts[0] = 1;
        for (int num: nums) {
            cumxor ^= num;
            res += cnts[cumxor];
            cnts[cumxor] += 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,3,1,2,4};
    cout << sol.beautifulSubarrays(nums) << '\n';
    return 0;
}