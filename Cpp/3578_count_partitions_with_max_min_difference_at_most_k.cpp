// https://leetcode.cn/problems/count-partitions-with-max-min-difference-at-most-k/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        // dp[i]: number of valid partitions until i (included), dp[0] = 1.
        // dp[i] = dp[left-1] + dp[left] + ... + dp[i-1], where left <= i is the minimum index
        // such that max(nums[left:i+1]) - min(nums[left:i+1]) <= k.
        // As i increases, left either stays the same or increavses.
        int mod = 1000000007;
        int left = 0, n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cumsum(n+1, 0);
        cumsum[1] = 1;
        priority_queue<pair<int, int>> max_pq, min_pq;
        max_pq.push(make_pair(nums[0], 0));
        min_pq.push(make_pair(-nums[0], 0));
        for (int i = 1; i < n; ++i) {
            max_pq.push(make_pair(nums[i], i));
            min_pq.push(make_pair(-nums[i], i));
            while (max_pq.top().first + min_pq.top().first > k) {
                left += 1;
                while (max_pq.top().second < left) max_pq.pop();
                while (min_pq.top().second < left) min_pq.pop();
            }
            if (left == 0) dp[i] = (cumsum[i] + 1) % mod;
            else dp[i] = (cumsum[i] - cumsum[left-1] + mod) % mod;
            cumsum[i+1] = (cumsum[i] + dp[i]) % mod;
        }
        return dp.back();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {9,4,1,3,7};
    int k = 4;
    cout << sol.countPartitions(nums, k) << '\n';
    return 0;
}