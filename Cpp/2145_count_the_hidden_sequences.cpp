// https://leetcode.cn/problems/count-the-hidden-sequences/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min_ = 0, max_ = 0, diff = 0;
        for (const auto &d: differences) {
            diff += d;
            min_ = min(min_, diff);
            max_ = max(max_, diff);
        }
        return max((long long)upper-lower-(max_-min_)+1, (long long)0);
    }
};

int main() {
    Solution sol;
    vector<int> differences = {1, -3, 4};
    int lower = 1, upper = 6;
    cout << sol.numberOfArrays(differences, lower, upper) << '\n';
    return 0;
}