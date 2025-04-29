// https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        unordered_set<int> s;
        for (int num: nums) {
            if (num < k) return -1;
            if (num > k && s.find(num) == s.end()) {
                res += 1;
                s.insert(num);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5,2,5,4,5};
    int k = 2;
    cout << sol.minOperations(nums, k) << '\n';
    return 0;
}
