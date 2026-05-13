// https://leetcode.cn/problems/minimum-moves-to-make-array-complementary/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(limit * 2 + 2, 0);
        for (int i = 0; i < n/2; ++i) {
            int a = nums[i], b = nums[n-1-i];
            int left = min(a, b) + 1;
            int right = max(a, b) + limit;

            // [2, left-1] += 2
            diff[2] += 2;
            diff[left] -= 2;

            // [left, right] += 1
            diff[left] += 1;
            diff[right+1] -=1;

            diff[a+b] -= 1;
            diff[a+b+1] += 1;
            
            // [right+1, limit*2] += 2
            diff[right+1] += 2;
        }

        int res = n, count = 0;
        for (int i = 2; i <= limit*2; ++i) {
            count += diff[i];
            res = min(res, count);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,4,3};
    int limit = 4;
    cout << sol.minMoves(nums, limit) << '\n';
    return 0;
}