// https://leetcode.cn/problems/maximum-ice-cream-bars/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        unordered_map<int, int> count;
        for (const int cost: costs) {
            count[cost] += 1;
        }

        int res = 0;
        int max_ = costs[0];
        for (const int cost: costs) {
            max_ = max(max_, cost);
        }
        for (int cost = 1; cost <= max_; ++cost) {
            int tmp = coins / cost;
            if (tmp == 0) {
                break;
            }
            int n = min(tmp, count[cost]);
            res += n;
            coins -= n * cost;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> costs = {1,3,2,4,1};
    int coins = 7;
    cout << sol.maxIceCream(costs, coins) << '\n';
    return 0;
}