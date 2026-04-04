// https://leetcode.cn/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int res = 0;
        vector<int> step(2, 1);
        for (int k = 0; k < 2; ++k) {
            if (startPos[k] > homePos[k]) step[k] = -1;
        }
        for (int i = homePos[0]; i != startPos[0]; i-=step[0]) {
            res += rowCosts[i];
        }
        for (int i = homePos[1]; i != startPos[1]; i-=step[1]) {
            res += colCosts[i];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> startPos = {1,0};
    vector<int> homePos = {2,3};
    vector<int> rowCosts = {5,4,3};
    vector<int> colCosts = {8,2,6,7};
    cout << sol.minCost(startPos, homePos, rowCosts, colCosts) << '\n';
    return 0;
}