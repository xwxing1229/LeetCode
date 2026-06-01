// https://leetcode.cn/problems/minimum-cost-of-buying-candies-with-discount/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int res = 0;
        int n = cost.size();
        sort(cost.rbegin(), cost.rend());
        for (int i = 0; i < n; ++i) {
            res += cost[i] * (i % 3 != 2);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> cost = {6,5,7,9,2,2};
    cout << sol.minimumCost(cost) << '\n';
    return 0;
}