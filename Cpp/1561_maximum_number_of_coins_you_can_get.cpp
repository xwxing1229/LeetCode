// https://leetcode.cn/problems/maximum-number-of-coins-you-can-get/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int res = 0, n = piles.size();
        for (int i = n-2; i >= n/3; i-=2) {
            res += piles[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {9,8,7,6,5,4,3,2,1};
    cout << sol.maxCoins(piles) << '\n';
    return 0;
}