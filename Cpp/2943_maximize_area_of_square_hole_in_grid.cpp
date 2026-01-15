// https://leetcode.cn/problems/maximize-area-of-square-hole-in-grid/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto MaxCont = [](vector<int> &bars) -> int {
            sort(bars.begin(), bars.end());
            int res = 1, cont = 1;
            int n = bars.size();
            for (int i = 1; i < n; ++i) {
                if (bars[i] - bars[i-1] == 1) {
                    cont += 1;
                    res = max(res, cont);
                }
                else {
                    cont = 1;
                }
            }
            return res;
        };
        int side = min(MaxCont(hBars), MaxCont(vBars)) + 1;
        return side * side;
    }
};

int main() {
    Solution sol;
    int n = 2, m = 3;
    vector<int> hBars = {2,3};
    vector<int> vBars = {2,4};
    cout << sol.maximizeSquareHoleArea(n, m, hBars, vBars) << '\n';
    return 0;
}