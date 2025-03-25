// https://leetcode.cn/problems/maximum-or/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rightor(n, 0);
        for (int i = n-2; i >= 0; --i) {
            rightor[i] = rightor[i+1] | nums[i+1];
        }
        long long res = 0, leftor = 0;
        for (int i = 0; i < n; ++i) {
            long long tmp = leftor | ((long long)nums[i] << k) | rightor[i];
            if (tmp > res) res = tmp;
            leftor |= nums[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {12, 9};
    int k = 1;
    cout << sol.maximumOr(nums, k) << '\n';
    return 0;
}