// https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-ii/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
    
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int num: nums) {
            pq.push(num);
        }
        while (pq.top() < k) {
            auto num1 = pq.top();
            pq.pop();
            auto num2 = pq.top();
            pq.pop();
            pq.push(num1 * 2 + num2);
            res += 1;
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