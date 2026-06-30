// https://leetcode.cn/problems/number-of-substrings-containing-all-three-characters/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int n = s.size(), right = 0;
        vector<int> count(3, 0);
        for (const char ch: s) {
            while (right < n && (count[0] < 1 || count[1] < 1 || count[2] < 1)) {
                count[s[right] - 'a'] += 1;
                right += 1;
            }
            if (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                res += n - right + 1;
            }
            count[ch - 'a'] -= 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "abcabc";
    cout << sol.numberOfSubstrings(s) << '\n';
    return 0;
}