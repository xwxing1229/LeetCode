// https://leetcode.cn/problems/maximum-number-of-balloons/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> count(26, 0);
        for (const char ch: text) {
            count[ch - 'a'] += 1;
        }

        int res = min(count['a'-'a'], min(count['b'-'a'], count['n'-'a']));
        res = min(res, min(count['l'-'a'], count['o'-'a']) / 2);
        return res;
    }
};

int main() {
    Solution sol;
    string text = "nlaebolko";
    cout << sol.maxNumberOfBalloons(text) << '\n';
    return 0;
}