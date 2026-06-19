// https://leetcode.cn/problems/find-the-highest-altitude/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0, res = 0;
        for (const int g: gain) {
            curr += g;
            res = max(res, curr);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> gain = {-5,1,5,0,-7};
    cout << sol.largestAltitude(gain) << '\n';
    return 0;
}