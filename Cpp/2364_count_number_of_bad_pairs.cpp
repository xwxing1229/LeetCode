// https://leetcode.cn/problems/count-number-of-bad-pairs/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long res = 0, n = nums.size();
        unordered_map<int, int> cnts;
        for (int i = 0; i < (int)n; ++i) {
            cnts[nums[i] - i] += 1;
        }
        
        for (auto it = cnts.begin(); it != cnts.end(); ++it) {
            long long v = it->second;
            res += (n - v) * v; 
        }
        return res / 2;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    cout << sol.countBadPairs(nums) << '\n';
    return 0;
}