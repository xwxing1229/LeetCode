// https://leetcode.cn/problems/total-waviness-of-numbers-in-range-i/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for (int num = num1; num <= num2; ++num) {
            string s = to_string(num);
            for (int i = 1; i < s.size()-1; ++i) {
                if ((s[i] < s[i-1] && s[i] < s[i+1])
                    || (s[i] > s[i-1] && s[i] > s[i+1])) {
                    res += 1;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    int num1 = 120, num2 = 130;
    cout << sol.totalWaviness(num1, num2) << '\n';
    return 0;
}