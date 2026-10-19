// https://leetcode.cn/problems/minimum-swaps-to-sort-by-digit-sum/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> digit_sum(n);
        for (int i = 0; i < n; ++i) {
            int s = 0, num = nums[i];
            while (num > 0) {
                s += num % 10;
                num /= 10;
            }
            digit_sum[i] = s;
        }

        vector<int> indices(n);
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return (digit_sum[i] < digit_sum[j]) ||
                (digit_sum[i] == digit_sum[j] && nums[i] < nums[j]);
        });

        vector<int> target_pos(n);
        for (int i = 0; i < n; ++i) {
            target_pos[indices[i]] = i;
        }

        vector<bool> visited(n, false);
        int cycles = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                cycles += 1;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = target_pos[j];
                }
            }
        }
        return n - cycles;
    }
};